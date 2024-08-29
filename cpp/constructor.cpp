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
    book()
    {
        cout << "enter book name :";
        gets(bname);

        cout << "enter book number :";
        cin >> bno;

        cout << "enter book price :";
        cin >> price;

        cout << "enter how many copies purchase :";
        cin >> copy;
    }

    /*  ~book()
      {
          int copy, total;

          cout << "book no:" << bno << endl;
          cout << "book price :" << price << endl;
          cout << "book name :" << bname << endl;
          cout << "copies :" << copy << endl;
          cout << "total_cost :" << total << endl;
      }
      */
    void disp()
    {
        float total;
        total = total_cost();
        cout << "book name :" << bname << endl;
        cout << "book no:" << bno << endl;
        cout << "book price :" << price << endl;

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
    obj.disp();

    return 0;
}