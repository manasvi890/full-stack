#include <iostream>
using namespace std;
int adno;
char name[20];
float marks;
int average;
class report
{

public:
    void readinfo()
    {
        cout << "enter adno=";
        cin >> adno;

        cout << "enter name=";
        cin >> name;

        cout << "enter marks=";
        cin >> marks;
    }
};
class report1
{

public:
    void showdata()
    {
        cout << "adno=" << adno << endl;
        cout << "name=" << name << endl;
        cout << "marks=" << marks << endl;
    }
};
class derive : public report, public report1
{
public:
    void answer()
    {
        cout << "average=" << marks / 5;
    }
};
int main()
{
    class derive obj;
    obj.readinfo();
    obj.showdata();
    obj.answer();

    return 0;
}