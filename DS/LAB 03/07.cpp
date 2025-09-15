#include <iostream>
#include <fstream>
#include <string>
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

class CircularList
{
    Node *head;
    Node *tail;

public:
    CircularList()
    {
        head = tail = NULL;
    }

    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);

        if (tail == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);

        if (tail == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAtPosition(int pos, int val)
    {
        if (pos < 1)
        {
            cout << "invalid position" << endl;
            return;
        }

        Node *newNode = new Node(val);
        if (pos == 1)
        {
            insertAtHead(val);
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < pos - 1 && temp->next != head; i++)
            {
                temp = temp->next;
            }
            if (temp->next == head)
            {
                cout << "Position out of bounds!" << endl;
                delete newNode;
            }
            else
            {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
    void deleteHead()
    {
        if (head == NULL)
        {
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }
    }

    void deleteValue(int pos)
    {
        if (head == NULL)
            return;

        if (pos == 1)
        {
            deleteHead();
        }

        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != head; i++)
        {
            temp = temp->next;
        }

        if (temp->next != head)
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
    void print()
    {
        if (head == NULL)
            return;

        cout << head->data << "->";
        Node *temp = head->next;

        while (temp != head)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
};

int main()
{
    CircularList cll;

    cll.insertAtHead(1);
    cll.insertAtHead(2);
    cll.insertAtHead(3);

    cll.print();
}