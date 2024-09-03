#include <iostream>
using namespace std;
class complex
{
    int a;
    int b;

public:
    void setdata(int x, int y)
    {
        a = x;
        b = y;
    }
    void display()
    {
        cout << "value of a=" << a << endl;
        cout << "value of b=" << b << endl;
    }
    void operator-()
    {
        a = -a;
        b = -b;
    }
};
int main()
{
    complex c;
    c.setdata(3, -4);
    c.display();
    cout << "after function call" << endl;
    -c;
    c.display();

    return 0;
}
