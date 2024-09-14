// restaurant menu system
#include <iostream>
using namespace std;
class hotel
{
public:
    int choice;
    int order, no_deals;
    int total;
    void menu()
    {

        cout << "|*---------------------------MENU-----------------------------*|" << endl;
        cout << endl;
        cout << "(1)   Manchurian               200 rs only." << endl;
        cout << "(2)   Pasta                    150 rs only." << endl;
        cout << "(3)   Dhosa                    250 rs only." << endl;
        cout << "(4)   Burgar                   100 rs only." << endl;
        cout << "(5)   Pizza                    450 rs only." << endl;
        cout << "(6)   Coke                     175 rs only." << endl;
    }
    void Order()
    {
        menu();

        cout << "Please select the order number: ";
        cin >> order;
        cout << "Please enter the number of deals: ";
        cin >> no_deals;
        cout << endl;

        switch (order)
        {

        case 1:
            cout << "Order : Manchurian  ." << endl;
            cout << "Number of deals : " << no_deals << endl;
            cout << "Price of each deal: $2 only." << endl;
            cout << "Total price : " << "$" << 2 * no_deals << " " << "only." << endl;
            cout << endl;
            cout << "~---------THANK YOU FOR COMING-----------~" << endl;
            break;
        case 2:
            cout << "Order :Pasta ." << endl;
            cout << "Number of deals : " << no_deals << endl;
            cout << "Price of each deal: $1.5 only." << endl;
            cout << "Total price : " << "$" << 1.5 * no_deals << " " << "only." << endl;
            cout << endl;
            cout << "~---------THANK YOU FOR COMING-----------~" << endl;
            break;
        case 3:
            cout << "Order :Dhosa   ." << endl;
            cout << "Number of deals : " << no_deals << endl;
            cout << "Price of each deal: $2.5 only." << endl;
            cout << "Total price : " << "$" << 2.5 * no_deals << " " << "only." << endl;
            cout << endl;
            cout << "~---------THANK YOU FOR COMING-----------~" << endl;
            break;
        case 4:
            cout << "Order : Burgar   ." << endl;
            cout << "Number of deals : " << no_deals << endl;
            cout << "Price of each deal: $1 only." << endl;
            cout << "Total price : " << "$" << 1 * no_deals << " " << "only." << endl;
            cout << endl;
            cout << "~---------THANK YOU FOR COMING-----------~" << endl;
            break;
        case 5:
            cout << "Order :   Pizza  ." << endl;
            cout << "Number of deals : " << no_deals << endl;
            cout << "Price of each deal: $4.5 only." << endl;
            cout << "Total price : " << "$" << 4.5 * no_deals << " " << "only." << endl;
            cout << endl;
            cout << "~---------THANK YOU FOR COMING-----------~" << endl;
            break;
        case 6:
            cout << "Order : Coke." << endl;
            cout << "Number of deals : " << no_deals << endl;
            cout << "Price of each deal: $1.75 only." << endl;
            cout << "Total price : " << "$" << 1.75 * no_deals << " " << "only." << endl;
            cout << endl;
            cout << "~---------THANK YOU FOR COMING-----------~" << endl;
            break;
        }
    }

    void bill()
    {
        Order();
        total = 2 * no_deals;
        cout << "-------------------------------------" << endl;
        cout << "                BILL                 " << endl;
        cout << "-------------------------------------" << endl;
        cout << "   Total :                " << total << endl;
    }
};

int main()
{
    int choice;
    int order, no_deal;
    class hotel obj;
    do
    {

        cout << "-------------------------------------" << endl;
        cout << "      WELCOME TO MY RESTORANT        " << endl;
        cout << "-------------------------------------" << endl;
        cout << "             Main Menu               " << endl;
        cout << "1)   Menu                            " << endl;
        cout << "2)   Order                           " << endl;
        cout << "3)   Bill                            " << endl;
        cout << "4)   Exit                            " << endl
             << endl;

        cout << "enter your choice :";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.menu();
            break;

        case 2:
            obj.Order();
            break;

        case 3:
            obj.bill();
            break;
        case 0:
            cout << "thank you for visit" << endl;
            break;
        default:
            cout << "enter valid number ";
            break;
        }

    } while (choice != 0);

    return 0;
}
