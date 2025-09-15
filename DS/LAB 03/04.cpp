#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class List
{
    Node *head;
    Node *tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    void pushBack(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void evenOdd()
    {
        if (head == nullptr)
            return;

        Node *evenHead = nullptr;
        Node *evenTail = nullptr;
        Node *oddHead = nullptr;
        Node *oddTail = nullptr;

        for (Node *curr = head; curr != nullptr; curr = curr->next)
        {
            if (curr->data % 2 == 0)
            {
                if (evenHead == nullptr)
                    evenHead = evenTail = curr;
                else
                {
                    evenTail->next = curr;
                    evenTail = curr;
                }
            }
            else
            {
                if (oddHead == nullptr)
                    oddHead = oddTail = curr;
                else
                {
                    oddTail->next = curr;
                    oddTail = curr;
                }
            }
        }

        if (evenHead == nullptr || oddHead == nullptr)
        {
            tail = head;
            while (tail != nullptr && tail->next != nullptr)
                tail = tail->next;
            return;
        }

        evenTail->next = oddHead;
        oddTail->next = nullptr;
        head = evenHead;
        tail = oddTail;
    }

    void printLL() const
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    List ll;
    int arr[] = {17, 15, 8, 12, 10, 5, 4, 1, 7, 6};
    for (int x : arr)
        ll.pushBack(x);

    cout << "Original list:\n";
    ll.printLL();

    ll.evenOdd();

    cout << "Modified list:\n";
    ll.printLL();
    return 0;
}
