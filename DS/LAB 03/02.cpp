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
        next = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List() { head = tail = NULL; }

    void pushFront(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void pushBack(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void rotate(int k)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        else
        {
            for (int i = 0; i < k; i++)
            {
                Node *temp = head;
                head = head->next;
                tail->next = temp;
                temp->next = nullptr;
                tail = temp;
            }
        }
    }

    void printLL()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{
    int arr[5] = {3, 1, 2, 5, 8};
    List ll;
    for (int i = 0; i < 5; i++)
    {
        ll.pushBack(arr[i]);
    }
    ll.printLL();

    ll.rotate(2);
    ll.printLL();

    return 0;
}