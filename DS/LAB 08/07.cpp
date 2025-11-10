#include <iostream>
#include <vector>
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

void inorder(Node *root, vector<int> &vals)
{
    if (!root)
        return;
    inorder(root->left, vals);
    vals.push_back(root->data);
    inorder(root->right, vals);
}

float findMedian(Node *root)
{
    vector<int> vals;
    inorder(root, vals);
    int n = vals.size();
    if (n == 0)
        return 0;
    if (n % 2 == 1)
        return vals[n / 2];
    return (vals[(n / 2) - 1] + vals[n / 2]) / 2.0;
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

    cout << "Median of BST: " << findMedian(root) << endl;
}
