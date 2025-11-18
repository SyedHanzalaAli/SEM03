#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

void storeInorder(Node *root, vector<int> &arr)
{
    if (!root)
        return;
    storeInorder(root->left, arr);
    arr.push_back(root->key);
    storeInorder(root->right, arr);
}

Node *buildAVL(vector<int> &arr, int l, int r)
{
    if (l > r)
        return NULL;
    int mid = (l + r) / 2;
    Node *root = new Node(arr[mid]);
    root->left = buildAVL(arr, l, mid - 1);
    root->right = buildAVL(arr, mid + 1, r);
    return root;
}

Node *convertBSTtoAVL(Node *bstRoot)
{
    vector<int> arr;
    storeInorder(bstRoot, arr);
    return buildAVL(arr, 0, arr.size() - 1);
}

Node *buildA()
{
    Node *root = new Node(10);
    root->left = new Node(6);
    root->left->left = new Node(4);
    root->left->right = new Node(8);
    return root;
}

Node *buildB()
{
    Node *root = new Node(10);
    root->right = new Node(16);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
    return root;
}
