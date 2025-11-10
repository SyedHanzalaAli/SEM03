#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node *insert(Node *root, int val)
{
    if (!root)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int countInRange(Node *root, int a, int b)
{
    if (!root)
        return 0;
    if (root->data >= a && root->data <= b)
        return 1 + countInRange(root->left, a, b) + countInRange(root->right, a, b);
    else if (root->data < a)
        return countInRange(root->right, a, b);
    else
        return countInRange(root->left, a, b);
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 40);
    root = insert(root, 100);

    int a = 5, b = 45;
    cout << "Number of nodes in range [" << a << ", " << b << "] = " << countInRange(root, a, b) << endl;
}
