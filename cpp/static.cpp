#include <iostream>
using namespace std;
class base
{
public:
    static int number;
    int i = 0;

    base()
    {
        number++;
        i++;
    }

    void Display()
    {
        cout << "static variable...." << i << "  " << number << endl;
    }
    static void display()
    {
        cout << "static variable==...." << number << endl;
    }
};

int base ::number = 10;

int main()
{
    base obj, obj1, obj2;
    obj.Display();
    obj1.Display();
    obj2.Display();

    base obj3;
    obj3.display();

    return 0;
}
