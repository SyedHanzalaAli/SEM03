#include <iostream>
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
        next = prev = nullptr;
    }
};

class DoublyLL
{
    Node *head;
    Node *tail;

public:
    void insertAtPosition(int data, int pos)
    {
        Node *newNode = new Node(data);

        if (pos < 1)
        {
            cout << "invalid position" << endl;
            return;
        }

        if (pos == 1)
        {
            newNode->next = head;
            if (head != nullptr)
            {
                head->prev = newNode;
            }
            head = newNode;
            if (tail == nullptr)
            {
                tail = newNode;
            }
            return;
        }

        Node *current = head;
        int count = 1;

        while (current != nullptr && count < pos - 1)
        {
            current = current->next;
            count++;
        }

        if (current == nullptr)
        {
            cout << "postion out of range" << endl;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != nullptr)
        {
            current->next->prev = newNode;
        }
        current->next = newNode;

        if (newNode->next == nullptr)
        {
            tail = newNode;
        }
    }

    void deleteAtPosition(int pos)
    {
        if (pos < 1)
        {
            cout << "Position out of range" << endl;
            return;
        }
        Node *curr = head;
        int count = 1;

        if (pos == 1)
        {
            if (head == nullptr)
            {
                cout << "List is empty" << endl;
                return;
            }
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
            delete curr;
            return;
        }

        while (curr != nullptr && count < pos)
        {
            curr = curr->next;
            count++;
        }

        if (curr == nullptr)
        {
            cout << "position out range" << endl;
            return;
        }

        if (curr->prev != nullptr)
        {
            curr->prev->next = curr->next;
        }
        if (curr->next != nullptr)
        {
            curr->next->prev = curr->prev;
        }
        if (curr == tail)
        {
            tail = curr->prev;
        }

        delete curr;
    }

    void displayList()
    {
        Node *curr = head;
        if (curr == nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }

        while (curr != nullptr)
        {
            cout << curr->data << "<->";
            curr = curr->next;
        }
        cout << "nullptr\n";
    }
};

int main()
{
    DoublyLL list;

    list.insertAtPosition(10, 1);
    list.insertAtPosition(20, 2);
    list.insertAtPosition(30, 3);
    list.insertAtPosition(40, 2);

    cout << "List after insertions: ";
    list.displayList();

    list.deleteAtPosition(3);

    cout << "List after deletion: ";
    list.displayList();

    list.deleteAtPosition(1);

    cout << "List after deletion: ";
    list.displayList();

    list.deleteAtPosition(2);

    cout << "List after deletion: ";
    list.displayList();

    return 0;
}
