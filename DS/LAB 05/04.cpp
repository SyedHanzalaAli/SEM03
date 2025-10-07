#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

bool search(Node *head, int val)
{
    if (head == nullptr)
    {
        return false;
    }
    if (head->data == val)
    {
        return true;
    }
    return search(head->next, val);
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    int targetValue = 30;

    if (search(head, targetValue))
    {
        cout << "Value " << targetValue << " found in the linked list.\n";
    }
    else
    {
        cout << "Value " << targetValue << " not found in the linked list.\n";
    }

    return 0;
}