#include <iostream>
using namespace std;
class base
{

public:
    int a;
    void setA()
    {
        cout << "enter a=";
        cin >> a;
    }
};

class base1
{

public:
    int b;
    void setB()
    {
        cout << "enter b=";
        cin >> b;
    }
};

class derive : public base1, public base
{

public:
    void product()
    {

        cout << "product is=" << a * b;
    }
};

int main()
{
    derive obj;
    obj.setA();
    obj.setB();
    obj.product();

   

    return 0;
}