#include <iostream>
using namespace std;

class bank
{

public:
    int acno;
    char name[50];
    int amount;
    int accountno;

    int money;

    void withdrawl()
    {

        if (amount <= money)
        {
            cout << "Invalid withdrawal amount or insufficient balance." << endl;
        }
        else
        {
            money -= amount;
            cout << "Withdrew " << amount << ". New balance is " << money << endl;
        }
    }

    void deposit()
    {

        if (money > 0)
        {
            money += amount;
            cout << "total amount :" << money << endl;

            cout << "deposit successfully...." << endl;
        }
        else
        {
            cout << "invalid deposit amount " << endl;
        }

        cout << endl;

        withdrawl();
    }

    void checkbalance()
    {

        if (acno == accountno)
        {

            cout << "--------------------------------------" << endl;
            cout << "     acno       name       amount     " << endl;
            cout << "--------------------------------------" << endl;
            cout << "" << accountno;
            cout << "           " << name;
            cout << "                     " << amount << endl;
        }
        else
        {
            cout << "account not found..." << endl;
        }

        deposit();
    }
};

int main()
{

    int choice;
    int acno;
    char name[50];
    int amount;
    int accountno;
    int money;

    do
    {
        cout << "--------------------------------" << endl;
        cout << "|============================= |" << endl;
        cout << "|       BANK MANAGEMENT        |" << endl;
        cout << "|============================= |" << endl;
        cout << "|        : Main Menu :         |" << endl;
        cout << "|                              |" << endl;
        cout << "|   1 . create new account     |" << endl;
        cout << "|   2 . withdrawl money        |" << endl;
        cout << "|   3 . diposit money          |" << endl;
        cout << "|   4 . show account           |" << endl;
        cout << "|   0 . exit                   |" << endl;
        cout << "|                              |" << endl;
        cout << "--------------------------------" << endl;

        cout << "-----------------------------------------" << endl;
        cout << "enter service option you need from bank :";
        cin >> choice;
        cout << "-----------------------------------------" << endl;

        class bank obj;

        switch (choice)
        {
        case 1:

            cout << "enter account number :";
            cin >> acno;

            cout << "enter account holder name :";
            cin >> name;
            cout << endl
                 << endl;

            cout << "enter initial amount :";
            cin >> amount;

            cout << endl
                 << endl;
            if (amount < 10000)
            {
                cout << "your account is not created" << endl;
            }
            else if (amount > 10000)
            {
                cout << "account created successfully..." << endl;
            }

            break;

        case 2:

            cout << "enter account number :";
            cin >> accountno;
            cout << endl;
            cout << "enter amount :";
            cin >> amount;
            obj.withdrawl();

            break;

        case 3:

            cout << "enter account number :";
            cin >> accountno;
            cout << endl;
            cout << "enter money you want to deposit...";
            cin >> money;
            cout << endl;
            obj.deposit();

            break;
        case 4:

            cout << "enter account number :";
            cin >> accountno;
            obj.checkbalance();

            break;

        case 0:

            cout << "Exiting...\n";
            return 0;
            break;

        default:

            cout << "invalid choice !! please try again..." << endl;
        }
    } while (choice != 0);

    return 0;
}
