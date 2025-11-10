#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

bool isBSTUtil(Node *root, int minVal, int maxVal)
{
    if (!root)
        return true;
    if (root->data <= minVal || root->data >= maxVal)
        return false;
    return isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node *root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main()
{
    Node *root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);
    root1->right->right = new Node(5);

    cout << "Tree 1 is " << (isBST(root1) ? "a BST" : "not a BST") << endl;

    Node *root2 = new Node(10);
    root2->left = new Node(5);
    root2->right = new Node(20);
    root2->left->right = new Node(9);
    root2->right->right = new Node(25);

    cout << "Tree 2 is " << (isBST(root2) ? "a BST" : "not a BST") << endl;
}
