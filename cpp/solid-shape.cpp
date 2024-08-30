#include <iostream>
using namespace std;
class shape
{
public:
    shape(int r)
    {
        int a = 3.14 * r * r;
        cout << "circle=" << a << endl;
    }
    shape(int b, int h)
    {
        int t = b * h / 2;
        cout << "triangle==" << t << endl;
    }
    shape(double l, double b)
    {
        int rect = l * b;
        cout << "rectangle=" << rect << endl;
    }
    shape(double lenth)
    {
        int s = lenth * lenth;
        cout << "square=" << s << endl;
    }
};
int main()
{
    shape circle(10), triangle(10, 20), rectangle(20.0, 30.0), square(10.0);

    return 0;
}