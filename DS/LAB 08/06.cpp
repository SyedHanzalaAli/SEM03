#include <iostream>
using namespace std;

struct Node
{
    int productID;
    int quantity;
    Node *left;
    Node *right;
    Node(int id, int qty) : productID(id), quantity(qty), left(NULL), right(NULL) {}
};

class BST
{
public:
    Node *root;
    BST() { root = NULL; }

    Node *insert(Node *root, int id, int qty)
    {
        if (!root)
            return new Node(id, qty);
        if (id < root->productID)
            root->left = insert(root->left, id, qty);
        else if (id > root->productID)
            root->right = insert(root->right, id, qty);
        else
            root->quantity += qty;
        return root;
    }

    void insertProduct(int id, int qty)
    {
        root = insert(root, id, qty);
    }

    Node *search(Node *root, int id)
    {
        if (!root || root->productID == id)
            return root;
        if (id < root->productID)
            return search(root->left, id);
        else
            return search(root->right, id);
    }

    void searchProduct(int id)
    {
        Node *res = search(root, id);
        if (res)
            cout << "Product ID: " << res->productID << ", Quantity: " << res->quantity << endl;
        else
            cout << "Product not found\n";
    }

    void updateQuantity(int id, int qty)
    {
        Node *res = search(root, id);
        if (res)
            res->quantity = qty;
        else
            cout << "Product not found\n";
    }

    void findMaxQuantity(Node *root, int &maxID, int &maxQty)
    {
        if (!root)
            return;
        if (root->quantity > maxQty)
        {
            maxQty = root->quantity;
            maxID = root->productID;
        }
        findMaxQuantity(root->left, maxID, maxQty);
        findMaxQuantity(root->right, maxID, maxQty);
    }

    void getMaxStock()
    {
        int maxID = -1, maxQty = -1;
        findMaxQuantity(root, maxID, maxQty);
        if (maxID != -1)
            cout << "Product with highest stock: ID = " << maxID << ", Quantity = " << maxQty << endl;
        else
            cout << "Inventory empty.\n";
    }

    void inorder(Node *root)
    {
        if (!root)
            return;
        inorder(root->left);
        cout << "ID: " << root->productID << ", Qty: " << root->quantity << endl;
        inorder(root->right);
    }

    void display()
    {
        inorder(root);
    }
};

int main()
{
    BST inventory;

    inventory.insertProduct(101, 50);
    inventory.insertProduct(103, 20);
    inventory.insertProduct(105, 75);
    inventory.insertProduct(102, 40);
    inventory.insertProduct(104, 60);

    cout << "Inventory:\n";
    inventory.display();

    cout << "\nSearch for Product ID 103:\n";
    inventory.searchProduct(103);

    cout << "\nUpdating Product ID 103 Quantity to 90...\n";
    inventory.updateQuantity(103, 90);

    cout << "\nUpdated Inventory:\n";
    inventory.display();

    cout << "\nFinding product with highest quantity:\n";
    inventory.getMaxStock();
}
