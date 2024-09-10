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
class derive : public base
{
public:
    int b;
    void setB()
    {
        cout << "enter b=";
        cin >> b;
    }
};
class derive1 : public derive
{
public:
    void product()
    {
        cout << "product is=" << a * b;
    }
};
int main()
{
    derive1 obj;
    obj.setA();
    obj.setB();
    obj.product();

    return 0;
}
