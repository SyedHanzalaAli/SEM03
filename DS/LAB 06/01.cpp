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
            return "Stack is empty.";
    }
    bool empty()
    {
        return ll.size() == 0;
    }
};

int main()
{
    Stack todoList;
    todoList.push("Finish report");
    todoList.push("Reply to client emails");
    todoList.push("Prepare presentation");

    if (todoList.empty())
        cout << "To-do list is empty.\n";
    else
        cout << "To-do list has tasks.\n";

    cout << "Top task: " << todoList.top() << endl;

    todoList.pop();

    cout << "After removing, new top task: " << todoList.top() << endl;

    return 0;
}
