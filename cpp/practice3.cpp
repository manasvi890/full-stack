#include <iostream>
using namespace std;
int main()
{
    int a, b;
    int *c;
    int *d;
    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;

    c = &a;
    d = &b;
    /*
        cout << "value of a=" << &c << endl;
        cout << "value of a=" << c << endl;
        cout << "value of b=" << &d << endl;
        cout << "value of b=" << d << endl;

        */

    *c = *c + *d;
    *d = *c - *d;
    *c = *c - *d;

    cout << "value of a=" << *c << endl;
    cout << "value of b=" << *d << endl;

    return 0;
}