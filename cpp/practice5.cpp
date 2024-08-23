#include <iostream>
using namespace std;
int sum = 0, num;
void perfect()
{
    cout << "enter number :";
    cin >> num;

    for (int i = 1; i <= num - 1; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
}

void explain()
{
    perfect();

    if (sum == num)
    {
        cout << "this is perfect number";
    }
    else
    {
        cout << "number is not perfect";
    }
}
int main()
{
    explain();
    return 0;
}