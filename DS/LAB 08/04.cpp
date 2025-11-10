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
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

bool search(Node *root, int val)
{
    if (!root)
        return false;
    if (root->data == val)
        return true;
    if (val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int val;
    cout << "Enter value to search: ";
    cin >> val;

    if (search(root, val))
        cout << "Value already exists in the tree.\n";
    else
    {
        cout << "Value not found. Inserting...\n";
        root = insert(root, val);
    }

    cout << "Updated tree (inorder): ";
    inorder(root);
    cout << endl;
}
