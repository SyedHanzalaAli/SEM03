#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

int findLength(Node* head, int length) {
    if (head == nullptr) {
        return length;
    }
    return findLength(head->next, length + 1);
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    int length = findLength(head, 0);

    cout << "Length of the linked list: " << length << endl;

    return 0;
}
