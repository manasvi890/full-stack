#include <iostream>
using namespace std;
class base
{
public:
    virtual void display() = 0;
    /*{
        cout << "base class call...";
    }*/
};
class derive : public base
{
public:
    void display()
    {
        cout << "derive class call...";
    }
};

int main()
{
    derive d;
    base *b;

    b = &d;
    b->display();

    return 0;
}
