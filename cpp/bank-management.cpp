#include <iostream>
using namespace std;
class bank
{

public:
    int acno;
    char name[50];
    int amount;
    int number;

    void menu()
    {
        cout << "-----------------------------" << endl;
        cout << "     BANK MANAGEMENT         " << endl;
        cout << "-----------------------------" << endl;
        cout << "1 . create new account" << endl;
        cout << "2 . withdrawl money" << endl;
        cout << "3 . diposit money" << endl;
        cout << "4.check balance" << endl;
        cout << "0 . exit" << endl;
    }
    void createac()
    {
        menu();
        cout << "enter service number you need from bank :";
        cin >> number;

        if (number == 1)
        {
            cout << "enter account number :";
            cin >> acno;

            cout << "enter account holder name :" << endl;
            cin >> name;

            cout << "...enter atleast 10,000 rs to create account...";

            cout << "enter amount :";
            cin >> amount;
            if (amount < 10000)
            {
                cout << "your account is not created";
            }
            else if (amount > 10000)
            {
                cout << "account created successfully...";
            }
            /*else if (number == 2)
            {
                cout << "enter money you want to withdral :";
                cin >> amount;
            }*/
        }
    }

    void withdrawl()
    {
        createac();
        if (number == 2)
        {
            cout << "enter account number :";
            cin >> acno;

            cout << "enter amount you need to withdrawl...";
            cin >> amount;

            cout << "....withdrawl successfull....";
        }
    }
};
int main()
{
    class bank obj;
    obj.withdrawl();

    return 0;
}