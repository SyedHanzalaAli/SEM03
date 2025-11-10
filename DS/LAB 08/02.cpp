#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Combatant
{
    string name;
    int hp;
    int attack;
    Combatant(string n = "", int h = 0, int a = 0) : name(n), hp(h), attack(a) {}
};

struct Node
{
    Combatant c;
    Node *left;
    Node *right;
    Node(Combatant combatant) : c(combatant), left(NULL), right(NULL) {}
};

Node *insert(Node *root, Combatant c)
{
    if (!root)
        return new Node(c);
    if (c.name < root->c.name)
        root->left = insert(root->left, c);
    else
        root->right = insert(root->right, c);
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
    if (name < root->c.name)
        root->left = deleteNode(root->left, name);
    else if (name > root->c.name)
        root->right = deleteNode(root->right, name);
    else
    {
        if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;
        Node *temp = findMin(root->right);
        root->c = temp->c;
        root->right = deleteNode(root->right, temp->c.name);
    }
    return root;
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->c.name << "(" << root->c.hp << "HP) ";
    inorder(root->right);
}

bool isEmpty(Node *root)
{
    return root == NULL;
}

int randomDamage()
{
    return rand() % 5;
}

void attack(Node *&attackerRoot, Node *&defenderRoot, bool playerTurn)
{
    Node *attacker = findMin(attackerRoot);
    Node *defender = findMin(defenderRoot);
    if (!attacker || !defender)
        return;
    int damage = attacker->c.attack + randomDamage();
    defender->c.hp -= damage;
    cout << (playerTurn ? "Hero" : "Enemy") << " " << attacker->c.name
         << " attacks " << (playerTurn ? "Enemy" : "Hero") << " " << defender->c.name
         << " for " << damage << " damage.\n";
    if (defender->c.hp <= 0)
    {
        cout << defender->c.name << " is defeated!\n";
        defenderRoot = deleteNode(defenderRoot, defender->c.name);
    }
}

int main()
{
    srand(time(0));
    Node *heroes = NULL;
    Node *enemies = NULL;

    heroes = insert(heroes, Combatant("Arthur", 30, 6));
    heroes = insert(heroes, Combatant("Baldric", 28, 5));
    heroes = insert(heroes, Combatant("Cedric", 32, 7));
    heroes = insert(heroes, Combatant("Doran", 26, 6));
    heroes = insert(heroes, Combatant("Eldon", 29, 5));

    enemies = insert(enemies, Combatant("Zarok", 25, 6));
    enemies = insert(enemies, Combatant("Yurik", 27, 5));
    enemies = insert(enemies, Combatant("Xandor", 30, 7));
    enemies = insert(enemies, Combatant("Wulfric", 26, 6));
    enemies = insert(enemies, Combatant("Varek", 28, 5));

    int round = 1;
    while (!isEmpty(heroes) && !isEmpty(enemies))
    {
        cout << "\n--- Round " << round++ << " ---\n";
        cout << "Heroes: ";
        inorder(heroes);
        cout << endl;
        cout << "Enemies: ";
        inorder(enemies);
        cout << endl;

        attack(heroes, enemies, true);
        if (isEmpty(enemies))
            break;
        attack(enemies, heroes, false);
    }

    if (isEmpty(enemies))
        cout << "\nHeroes win the battle!\n";
    else
        cout << "\nEnemies win the battle!\n";
}
