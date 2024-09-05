#include <iostream>
using namespace std;
class base
{
private:
    int a;
    int b;

public:
    int c;

    void getdata()
    {
        a = 10;
        b = 20;
    }

    void display()
    {
        cout << "a=" << a << endl;
        cout << "b=" << b << endl;
    }
};

class derive : public base
{

public:
    void displayalldata()
    {
        c = 30;
        getdata();
        display();
        cout << "c=" << c << endl;
    }
};
int main()
{
    derive obj;
    obj.displayalldata();

    return 0;
}