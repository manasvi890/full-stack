#include <iostream>
using namespace std;
int main()
{
    int i, j, n, k;
    cout << "n=";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        for (k = n; k >= i; k--)
        {
            cout << " ";
        }

        for (j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (i = n - 1; i >= 1; i--)
    {
        for (k = i; k <= n; k++)
        {
            cout << " ";
        }

        for (j = i; j >= 1; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
    /*cout << "hello world";*/
    return 0;
}