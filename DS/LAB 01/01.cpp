#include <iostream>
using namespace std;

class BankAccount
{
    double bal; // balance

public:
    BankAccount()
    {
        bal = 0.0;
    }
    BankAccount(double b)
    {
        bal = b;
    }
    BankAccount(const BankAccount &other)
    {
        bal = other.bal;
    }
    void withdraw(double amount)
    {
        if (amount <= bal)
        {
            bal -= amount;
        }
        else
        {
            cout << "Insufficient Balance" << endl;
        }
    }
    double getBalance() const
    {
        return bal;
    }
};

int main()
{
    BankAccount a1;
    cout << "balance in account 1 : " << a1.getBalance() << endl;

    BankAccount a2(1000.0);
    cout << "balance in account 2 : " << a2.getBalance() << endl;

    BankAccount a3(a2);
    a3.withdraw(200.0);

    cout << "Balance of account 3 : " << a3.getBalance() << endl;
    cout << "balance in account 2 : " << a2.getBalance() << endl;

    return 0;
}