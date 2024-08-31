#include <iostream>
using namespace std;
class complex
{
    int a;
    int b;

public:
    complex()
    {
        a = 0;
        b = 0;
    }

    complex(int x, int y)
    {
        a = x;
        b = y;
    }

    void display()
    {
        cout << "value of a=" << a << endl;
        cout << "value of b=" << b << endl;
    }
    complex operator+(complex t)
    {
        complex r;
        r.a = a + t.a;
        r.b = b + t.b;
    }
    complex operator-(complex t)
    {
        complex r;
        r.a = a - t.a;
        r.b = b - t.b;
    }
};
int main()
{
    class complex x(10, 20), y(30, 40), z;
    cout << "object of x is=" << endl;
    x.display();
    cout << "object of y is=" << endl;
    y.display();

    z = x + y;

    cout << "object is=" << endl;
    z.display();
    z = x - y;
    cout << "object is=" << endl;
    z.display();

    return 0;
}
