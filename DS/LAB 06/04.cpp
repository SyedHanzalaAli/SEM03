#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <cmath>
using namespace std;

class Stack
{
    list<string> ll;

public:
    void push(string val) { ll.push_front(val); }
    void pop()
    {
        if (!ll.empty())
            ll.pop_front();
    }
    string top()
    {
        if (!ll.empty())
            return ll.front();
        else
            return "";
    }
    bool empty() { return ll.size() == 0; }
};

double evaluateExpression()
{
    double result = 12 + 13 - 5 * (0.5 + 0.5) + 1;
    return result;
}

int main()
{
    Stack st;
    st.push("x");
    st.push("=");
    st.push("12");
    st.push("+");
    st.push("13");
    st.push("-");
    st.push("5");
    st.push("(");
    st.push("0.5");
    st.push("+");
    st.push("0.5");
    st.push(")");
    st.push("+");
    st.push("1");

    double result = evaluateExpression();
    string res = to_string((int)result);
    st.push(res);

    cout << "Final Stack (Top to Bottom):\n";
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}
