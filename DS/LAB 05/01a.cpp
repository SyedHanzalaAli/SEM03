#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLL
{
    Node *head;
    Node *tail;

public:
    SinglyLL()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);

        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printReverse(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        printReverse(node->next);
        cout << node->data << "->";
    }

    void printLLReverse()
    {
        printReverse(head);
    }
};

int main()
{

    SinglyLL l;

    l.insertAtEnd(1);
    l.insertAtEnd(2);
    l.insertAtEnd(3);
    l.insertAtEnd(4);

    l.printLLReverse();

    return 0;
}