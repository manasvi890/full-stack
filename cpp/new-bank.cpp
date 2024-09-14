#include <iostream>
#include <string>

using namespace std;

const int MAX_ACCOUNTS = 100; // Maximum number of accounts

class Account
{
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    Account() : accountNumber(0), balance(0.0) {} // Default constructor

    Account(int accNum, string holder, double initialBalance)
        : accountNumber(accNum), accountHolder(holder), balance(initialBalance) {}

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited " << amount << ". New balance is " << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew " << amount << ". New balance is " << balance << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount or insufficient balance." << endl;
        }
    }

    void checkBalance() const
    {
        cout << "Current balance for account " << accountNumber << " is " << balance << endl;
    }

    int getAccountNumber() const
    {
        return accountNumber;
    }

    void setAccount(int accNum, string holder, double initialBalance)
    {
        accountNumber = accNum;
        accountHolder = holder;
        balance = initialBalance;
    }
};

class Bank
{
private:
    Account accounts[MAX_ACCOUNTS];
    int accountCount;

public:
    Bank() : accountCount(0) {}

    void createAccount(int accNum, string holder, double initialBalance)
    {
        if (accountCount < MAX_ACCOUNTS)
        {
            accounts[accountCount].setAccount(accNum, holder, initialBalance);
            accountCount++;
            cout << "Account created successfully." << endl;
        }
        else
        {
            cout << "Account limit reached. Cannot create new account." << endl;
        }
    }

    Account *getAccount(int accNum)
    {
        for (int i = 0; i < accountCount; ++i)
        {
            if (accounts[i].getAccountNumber() == accNum)
            {
                return &accounts[i];
            }
        }
        cout << "Account not found." << endl;
        return nullptr;
    }
};

int main()
{
    Bank bank;
    int choice;
    int accNum;
    string holder;
    double amount;

    while (true)
    {
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter account holder name: ";
            cin.ignore(); // To ignore leftover newline character
            getline(cin, holder);
            cout << "Enter initial balance: ";
            cin >> amount;
            bank.createAccount(accNum, holder, amount);
            break;

        case 2:
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            {
                Account *acc = bank.getAccount(accNum);
                if (acc)
                    acc->deposit(amount);
            }
            break;

        case 3:
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            {
                Account *acc = bank.getAccount(accNum);
                if (acc)
                    acc->withdraw(amount);
            }
            break;

        case 4:
            cout << "Enter account number: ";
            cin >> accNum;
            {
                Account *acc = bank.getAccount(accNum);
                if (acc)
                    acc->checkBalance();
            }
            break;

        case 5:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
