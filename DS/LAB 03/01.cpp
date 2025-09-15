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

    void insert(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "invalid position" << endl;
            return;
        }
        else if (pos == 0)
        {
            pushFront(val);
            return;
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "invalid position" << endl;
                return;
            }

            temp = temp->next;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteValue(int val)
    {
        if (head == NULL)
            return;
        if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL && temp->next->data != val)
        {
            temp = temp->next;
        }
        if (temp->next != NULL)
        {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
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

    ll.pushBack(9);
    ll.insert(11, 3);
    ll.pushFront(4);
    ll.printLL();

    ll.deleteValue(1);
    ll.deleteValue(2);
    ll.deleteValue(5);
    ll.printLL();

    return 0;
}