
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class SavingsAccount
{
private:
    int accountNumber;
    double balance;

    static const int CAPACITY = 10;

    struct Transaction
    {
        string type;
        double amount;
        double balanceAfter;
    };

    Transaction transactions[CAPACITY];
    int count;
    int nextIndex;

    void addTransaction(string type, double amount);

public:
    SavingsAccount(int accNo, double initialBalance);

    void deposit(double amount);
    void withdraw(double amount);
    void miniStatement();
};

// Constructor defined outside the class
SavingsAccount::SavingsAccount(int accNo, double initialBalance)
{
    accountNumber = accNo;
    balance = initialBalance;
    count = 0;
    nextIndex = 0;
}

// Stores a transaction using a circular buffer
void SavingsAccount::addTransaction(string type, double amount)
{
    transactions[nextIndex].type = type;
    transactions[nextIndex].amount = amount;
    transactions[nextIndex].balanceAfter = balance;

    nextIndex = (nextIndex + 1) % CAPACITY;

    if (count < CAPACITY)
        count++;
}

// Deposit function
void SavingsAccount::deposit(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid deposit amount.\n";
        return;
    }

    balance += amount;
    addTransaction("Deposit", amount);

    cout << "Deposit successful: Rs." << amount << '\n';
}

// Withdrawal function
void SavingsAccount::withdraw(double amount)
{
    if (amount <= 0 || amount > balance)
    {
        cout << "Invalid withdrawal.\n";
        return;
    }

    balance -= amount;
    addTransaction("Withdrawal", amount);

    cout << "Withdrawal successful: Rs." << amount << '\n';
}

// Displays transactions from oldest to newest
void SavingsAccount::miniStatement()
{
    cout << "\nAccount Number: " << accountNumber << '\n';
    cout << "Current Balance: Rs." << balance << '\n';

    cout << "\nLast " << count << " Transactions\n";
    cout << "------------------------------------------\n";

    cout << left << setw(15) << "Type"
         << setw(12) << "Amount"
         << "Balance After\n";

    int start = (nextIndex - count + CAPACITY) % CAPACITY;

    for (int i = 0; i < count; i++)
    {
        int index = (start + i) % CAPACITY;

        cout << left << setw(15) << transactions[index].type
             << setw(12) << transactions[index].amount
             << transactions[index].balanceAfter << '\n';
    }
}

int main()
{
    cout << fixed << setprecision(2);

    SavingsAccount account(1001, 5000);

    account.deposit(1000);
    account.withdraw(500);
    account.deposit(200);
    account.withdraw(100);
    account.deposit(300);
    account.withdraw(200);
    account.deposit(400);
    account.deposit(500);
    account.withdraw(250);
    account.deposit(600);
    account.withdraw(300);
    account.deposit(700);

    account.miniStatement();

    return 0;
}
