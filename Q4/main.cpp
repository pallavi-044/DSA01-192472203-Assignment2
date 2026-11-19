#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class SavingsAccount
{
private:
    int accountNumber;
    double balance;
    double transactions[10];
    int count;

    void addTransaction(double amount)
    {
        if (count == 10)
        {
            for (int i = 0; i < 9; i++)
                transactions[i] = transactions[i + 1];

            count--;
        }

        transactions[count++] = amount;
    }

public:
    SavingsAccount(int acc, double initial)
        : accountNumber(acc), balance(initial), count(0) {}

    void deposit(double amount);
    void withdraw(double amount);
    void miniStatement() const;
};

void SavingsAccount::deposit(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid deposit\n";
        return;
    }

    balance += amount;
    addTransaction(amount);
}

void SavingsAccount::withdraw(double amount)
{
    if (amount <= 0 || amount > balance)
    {
        cout << "Invalid withdrawal\n";
        return;
    }

    balance -= amount;
    addTransaction(-amount);
}

void SavingsAccount::miniStatement() const
{
    cout << "\nSAVINGS ACCOUNT MINI STATEMENT\n";
    cout << "Account Number: " << accountNumber << '\n';
    cout << fixed << setprecision(2);

    cout << "Recent Transactions:\n";

    for (int i = 0; i < count; i++)
    {
        if (transactions[i] >= 0)
            cout << "Deposit: Rs. " << transactions[i] << '\n';
        else
            cout << "Withdrawal: Rs. " << -transactions[i] << '\n';
    }

    cout << "Final Balance: Rs. " << balance << '\n';
}

int main()
{
    SavingsAccount account(1001, 1000);

    account.deposit(500);
    account.withdraw(200);
    account.deposit(300);
    account.withdraw(100);
    account.deposit(400);
    account.withdraw(50);
    account.deposit(250);
    account.withdraw(150);
    account.deposit(600);
    account.withdraw(300);
    account.deposit(700);
    account.withdraw(100);

    account.miniStatement();

    return 0;
}