#include <iostream>
using namespace std;
class base
{

protected:
    int a;

public:
    void A()
    {
        cout << "enter a=";
        cin >> a;
    }
};

class base1
{
protected:
    int b;

public:
    void B()
    {
        cout << "enter b=";
        cin >> b;
    }
};
class derive : public base, public base1
{
public:
    void product()
    {
        cout << "get a and b=" << a * b;
    }
};
int main()
{
    class derive c;
    c.A();
    c.B();
    c.product();

    return 0;
}