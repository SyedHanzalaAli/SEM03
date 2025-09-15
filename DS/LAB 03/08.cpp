#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList
{
    Node *head;
    Node *tail;

public:
    DoublyList()
    {
        head = tail = NULL;
    }
    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "list empty \n";
            return;
        }

        Node *temp = head;
        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }

        temp->next = NULL;
        delete temp;
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "list empty \n";
            return;
        }

        Node *temp = tail;
        tail = tail->prev;

        if (tail != NULL)
        {
            tail->next = NULL;
        }

        temp->prev = NULL;
        delete temp;
    }

    void merge(DoublyList &L, DoublyList &M)
    {
        if (L.tail != nullptr)
        {
            L.tail->next = M.head;
            if (M.head != nullptr)
            {
                M.head->prev = L.tail;
            }
            L.tail = M.tail;
        }
        else
        {
            L.head = M.head;
            L.tail = M.tail;
        }
        M.head = M.tail = nullptr;
    }

    void print()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "<=>";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    DoublyList dll;

    dll.push_front(1);
    dll.push_front(2);
    dll.push_back(3);

    dll.print();

    // dll.pop_front();
    // dll.print();

    dll.pop_back();
    dll.print();

    return 0;
}