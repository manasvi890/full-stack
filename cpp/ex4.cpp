#include <iostream>
using namespace std;
class book
{
private:
    int bno, copy;
    char bname;
    float price;
    float total;
    void total_cost();

public:
    void input()
    {
        cout << "enter book no :";
        cin >> bno;

        cout << "enter book price :";
        cin >> price;

        cout << "enter how many copies customer purchase :";
        cin >> copy;

        cout << "enter book name :";
        cin >> bname;

        total_cost();
    }

    void disp()
    {
        cout << "--------------------------" << endl;
        cout << "book no:" << bno << endl;
        cout << "book name :" << bname << endl;
        cout << "book price :" << price << endl;
        cout << "copies :" << copy << endl;
        cout << "total_cost :" << total << endl;
    }
};

void book ::total_cost()
{
    total = price * copy;
};

int main()
{
    class book obj;
    obj.input();
    
    obj.disp();

    return 0;
}