#include <iostream>
using namespace std;
class book
{
private:
    int bno;
    char bname[100];
    float price;
    int copy;

    int total_cost();

public:
    void input()
    {
        cout << "enter book no :";
        cin >> bno;

        cout << "enter book price :";
        cin >> price;

        cout << "enter book name :";
        cin >> bname;
    }

    void purchase()
    {

        cout << "enter how many copies customer purchase :" << endl;
        cin >> copy;
    }
    void disp()
    {
        float total;
        total = total_cost();
        cout << "book no:" << bno << endl;

        cout << "book price :" << price << endl;
        cout << "book name :" << bname << endl;
        cout << "copies :" << copy << endl;
        cout << "total_cost :" << total << endl;
    }
};

int book ::total_cost()
{
    float total;
    return total = price * copy;
};

int main()
{
    class book obj;
    obj.input();

    obj.purchase();
    obj.disp();

    return 0;
}