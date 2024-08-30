#include <iostream>
using namespace std;
class shape
{
public:
    void various(int l, int b, int h)
    {
        int cuboid = l * b * h;
        cout << "cuboid=" << cuboid << endl;
    }
    void various(int a)
    {
        int cube = a * a * a;
        cout << "cube=" << cube << endl;
    }
    void various(double r, double h)
    {
        int cylinder = 22.7 * r * r * h;
        cout << "cylinder=" << cylinder << endl;
    }
    void various(int r, int height)
    {
        int cone = 22.7 * r * r * height / 3;
        cout << "cone=" << cone << endl;
    }
    void various(double re)
    {
        int sphere = 4 * 22.7 * re * re * re / 3;
        cout << "sphere=" << sphere << endl;
    }
};
int main()
{
    shape obj;
    obj.various(10, 20, 30);
    obj.various(10);
    obj.various(10.0, 20.0);
    obj.various(10, 20);
    obj.various(10);

    return 0;
}