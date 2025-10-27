#include <iostream>
#include <string>
#include <cmath>
using namespace std;
struct Node
{
    string name;
    int score;
    Node *next;
    Node(string n, int s)
    {
        name = n;
        score = s;
        next = NULL;
    }
};
void addNode(Node **head, string name, int score)
{
    Node *newNode = new Node(name, score);
    newNode->next = *head;
    *head = newNode;
}
int getMax(Node *head)
{
    int mx = 0;
    while (head)
    {
        if (head->score > mx)
            mx = head->score;
        head = head->next;
    }
    return mx;
}
void countSort(Node **head, int exp)
{
    Node *buckets[10] = {NULL};
    Node *curr = *head;
    while (curr)
    {
        int index = (curr->score / exp) % 10;
        Node *temp = new Node(curr->name, curr->score);
        temp->next = buckets[index];
        buckets[index] = temp;
        curr = curr->next;
    }
    Node *output = NULL;
    for (int i = 9; i >= 0; i--)
    {
        Node *tmp = buckets[i];
        while (tmp)
        {
            Node *next = tmp->next;
            tmp->next = output;
            output = tmp;
            tmp = next;
        }
    }
    *head = output;
}
void radixSort(Node **head)
{
    int m = getMax(*head);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(head, exp);
}
void printList(Node *head)
{
    while (head)
    {
        cout << head->name << " " << head->score << endl;
        head = head->next;
    }
}
int main()
{
    Node *head = NULL;
    addNode(&head, "Ayan", 90);
    addNode(&head, "Zameer", 60);
    addNode(&head, "Sara", 70);
    addNode(&head, "Sohail", 30);
    addNode(&head, "Ahmed", 20);
    radixSort(&head);
    printList(head);
}
