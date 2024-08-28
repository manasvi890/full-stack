#include <iostream>

using namespace std;
class test
{
private:
    int tcode;
    char desp[20];
    int candidate;
    int center;
    void calcntr();

public:
    void schedule()
    {

        cout << "enter description :";
        gets(desp);

        cout << "enter test code :";
        cin >> tcode;

        cout << "enter candidate number :";
        cin >> candidate;

        calcntr();
    }
    void disptest()
    {
        cout << "test code :" << tcode << endl;
        cout << "description :" << desp << endl;
        cout << "candidate no :" << candidate << endl;
        cout << "center :" << center << endl;
    }
};
void test::calcntr()
{
    center = candidate / 100 + 1;
};
int main()
{
    class test obj;
    obj.schedule();
    obj.disptest();

    return 0;
}