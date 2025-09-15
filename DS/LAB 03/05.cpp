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

    bool palindrome()
    {
        if (head == nullptr || head->next == nullptr)
            return true;

        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *prev = nullptr;
        Node *curr = slow;
        while (curr != nullptr)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        Node *firstHalf = head;
        Node *secondHalf = prev;
        while (secondHalf != nullptr)
        {
            if (firstHalf->data != secondHalf->data)
            {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
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
    int arr[] = {1, 0, 2, 0, 1};
    for (int x : arr)
        ll.pushBack(x);

    ll.printLL();

    if (ll.palindrome())
        cout << "Linked List is a Palindrome\n";
    else
        cout << "Linked List is NOT a Palindrome\n";

    return 0;
}
