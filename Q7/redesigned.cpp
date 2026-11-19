#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
    string accountNumber;
    double balance;
    string transactions[10];
    int count;
    int next;

public:
    SavingsAccount(string acc, double initial)
        : accountNumber(acc), balance(initial), count(0), next(0) {}

    void addTransaction(string transaction) {
        transactions[next] = transaction;
        next = (next + 1) % 10;

        if (count < 10)
            count++;
    }

    void deposit(double amount) {
        balance += amount;
        addTransaction("Deposit: Rs. " + to_string(amount));
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            addTransaction("Withdrawal: Rs. " + to_string(amount));
        } else {
            cout << "Insufficient balance\n";
        }
    }

    void miniStatement() const {
        cout << "\nACCOUNT: " << accountNumber << '\n';
        cout << "BALANCE: Rs. " << balance << '\n';
        cout << "\nLAST " << count << " TRANSACTIONS\n";

        int start = (next - count + 10) % 10;

        for (int i = 0; i < count; i++) {
            cout << transactions[(start + i) % 10] << '\n';
        }
    }
};

int main() {
    SavingsAccount account("ACC1001", 1000);

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