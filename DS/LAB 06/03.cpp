#include <iostream>
#include <string>
#include <list>
using namespace std;

class Stack
{
    list<string> ll;

public:
    void push(string val)
    {
        ll.push_front(val);
    }
    void pop()
    {
        if (!ll.empty())
            ll.pop_front();
        else
            cout << "Stack is empty. Nothing to pop.\n";
    }
    string top()
    {
        if (!ll.empty())
            return ll.front();
        else
            return "";
    }
    bool empty()
    {
        return ll.size() == 0;
    }
};

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(string infix)
{
    Stack st;
    string postfix = "";

    for (char c : infix)
    {
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            string s(1, c);
            st.push(s);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != "(")
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (isOperator(c))
        {
            string s(1, c);
            while (!st.empty() && precedence(st.top()[0]) >= precedence(c))
            {
                if (c == '^' && st.top()[0] == '^')
                    break;
                postfix += st.top();
                st.pop();
            }
            st.push(s);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << infixToPostfix(infix) << endl;
    return 0;
}
