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

    void deleteValue(int pos)
    {
        if (head == NULL)
            return;

        if (pos == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp != NULL && temp->next != NULL)
        {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
        else
        {
            cout << "Position out of bounds" << endl;
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
    cout << "Array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    List ll;
    for (int i = 0; i < 5; i++)
    {
        ll.pushBack(arr[i]);
    }
    ll.printLL();

    ll.deleteValue(2);
    ll.printLL();

    ll.deleteValue(1);
    ll.printLL();

    ll.deleteValue(10);
    ll.printLL();

    return 0;
}
