#include <iostream>
#include <string>
#include <list>
#include <stack>
using namespace std;

void displayList(list<string> l)
{
    cout << "Current browsing history : ";
    for (auto &site : l)
    {
        cout << site << " ";
    }
    cout << endl;
}

int main()
{
    list<string> history;
    stack<string> backStack;

    string sites[] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};
    for (string site : sites)
    {
        history.push_front(site);
        backStack.push(site);
    }
    cout << "After visiting 5 websites : " << endl;
    displayList(history);

    cout << "\nUser clicks back twice" << endl;
    for (int i = 0; i < 2; i++)
    {
        if (!backStack.empty())
        {
            backStack.pop();
        }
        if (!history.empty())
        {
            history.pop_front();
        }
    }

    cout << "\nAfter going back twice : " << endl;
    displayList(history);

    cout << "Current page : " << history.front() << endl;
    return 0;
}