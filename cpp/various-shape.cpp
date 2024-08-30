#include <iostream>
using namespace std;
class various
{

public:
    various(int l, int b, int h)
    {
        int cuboid = l * b * h;
        cout << "cuboid=" << cuboid << endl;
    }
    various(int a)
    {
        int cube = a * a * a;
        cout << "cube=" << cube << endl;
    }
    various(double r, double h)
    {
        int cylinder = 22.7 * r * r * h;
        cout << "cylinder=" << cylinder << endl;
    }
    various(int r, int height)
    {
        int cone = 22.7 * r * r * height / 3;
        cout << "cone=" << cone << endl;
    }
    various(double re)
    {
        int sphere = 4 * 22.7 * re * re * re / 3;
        cout << "sphere=" << sphere << endl;
    }
};
int main()
{
    various cuboid(10, 20, 30), cube(40), cylinder(20.0, 40.0), cone(20, 50), sphere(50.0);

    return 0;
}
