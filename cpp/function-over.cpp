#include <iostream>
using namespace std;
class shape
{
public:
    void solid(int r)
    {
        int a = 3.14 * r * r;
        cout << "circle=" << a << endl;
    }
    void solid(int b, int h)
    {
        int t = b * h / 2;
        cout << "triangle==" << t << endl;
    }
    void solid(double l, double b)
    {
        int rect = l * b;
        cout << "rectangle=" << rect << endl;
    }
    void solid(double lenth)
    {
        int s = lenth * lenth;
        cout << "square=" << s << endl;
    }
};
int main()
{
    shape obj;
    obj.solid(10);
    obj.solid(10, 20);
    obj.solid(10.0, 20.0);
    obj.solid(10.0);

    return 0;
}