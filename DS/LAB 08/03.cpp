#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Student
{
    string name;
    int roll;
    int score;
    Student(string n = "", int r = 0, int s = 0) : name(n), roll(r), score(s) {}
};

struct Node
{
    Student s;
    Node *left;
    Node *right;
    Node(Student student) : s(student), left(NULL), right(NULL) {}
};

Node *insert(Node *root, Student s)
{
    if (!root)
        return new Node(s);
    if (s.name < root->s.name)
        root->left = insert(root->left, s);
    else
        root->right = insert(root->right, s);
    return root;
}

Node *findMin(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, string name)
{
    if (!root)
        return root;
    if (name < root->s.name)
        root->left = deleteNode(root->left, name);
    else if (name > root->s.name)
        root->right = deleteNode(root->right, name);
    else
    {
        if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;
        Node *temp = findMin(root->right);
        root->s = temp->s;
        root->right = deleteNode(root->right, temp->s.name);
    }
    return root;
}

Node *search(Node *root, string name)
{
    if (!root || root->s.name == name)
        return root;
    if (name < root->s.name)
        return search(root->left, name);
    else
        return search(root->right, name);
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->s.name << " (" << root->s.roll << ", " << root->s.score << ")\n";
    inorder(root->right);
}

Node *deleteLowScores(Node *root)
{
    if (!root)
        return NULL;
    root->left = deleteLowScores(root->left);
    root->right = deleteLowScores(root->right);
    if (root->s.score < 10)
        return deleteNode(root, root->s.name);
    return root;
}

void findMaxScore(Node *root, Student &maxS)
{
    if (!root)
        return;
    if (root->s.score > maxS.score)
        maxS = root->s;
    findMaxScore(root->left, maxS);
    findMaxScore(root->right, maxS);
}

int main()
{
    srand(time(0));
    Student students[10] = {
        {"Ali", 1, 12}, {"Bilal", 2, 8}, {"Hanzala", 3, 15}, {"Omar", 4, 20}, {"Usman", 5, 9}, {"Ahmed", 6, 18}, {"Zain", 7, 11}, {"Taha", 8, 5}, {"Hassan", 9, 14}, {"Fahad", 10, 7}};

    Node *root = NULL;
    for (int i = 0; i < 7; i++)
    {
        int idx = rand() % 10;
        root = insert(root, students[idx]);
    }

    cout << "All Students in BST:\n";
    inorder(root);

    cout << "\nSearch for 'Omar':\n";
    Node *res = search(root, "Omar");
    if (res)
        cout << res->s.name << " found with score " << res->s.score << endl;
    else
        cout << "Not found\n";

    cout << "\nDeleting students with score < 10...\n";
    root = deleteLowScores(root);
    inorder(root);

    cout << "\nStudent with Max Score:\n";
    Student maxS("", 0, 0);
    findMaxScore(root, maxS);
    cout << maxS.name << " (" << maxS.roll << ", " << maxS.score << ")\n";
}
