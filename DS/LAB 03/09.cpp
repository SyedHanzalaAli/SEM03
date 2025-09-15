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

    void rearrangeList()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }

        Node *odd = head;
        Node *even = head->next;
        Node *evenHead = even;

        while (odd->next != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            odd = odd->next;

            if (odd->next != nullptr)
            {
                even->next = odd->next;
                even = even->next;
            }
            else
            {
                even->next = nullptr;
                break;
            }
        }
        even->next = nullptr;

        Node *prev = nullptr;
        Node *curr = evenHead;

        while (curr != nullptr)
        {
            Node *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        Node *reversedHead = prev;

        odd->next = reversedHead;

        if (reversedHead != nullptr)
        {
            while (reversedHead->next != nullptr)
            {
                reversedHead = reversedHead->next;
            }
            tail = reversedHead;
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
    List list;
    int arr[] = {10, 4, 9, 1, 3, 5, 9, 4};
    for (int val : arr)
    {
        list.pushBack(val);
    }

    cout << "Original list: ";
    list.printLL();

    list.rearrangeList();

    cout << "Modified list: ";
    list.printLL();

    return 0;
}