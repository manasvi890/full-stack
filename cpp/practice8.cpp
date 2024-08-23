#include <iostream>
using namespace std;
int main()
{
    int i, j;
    char ch = 'A';
    for (int i = 0; i <= 5; i++)
    {
        for (int j = 0; i <= 5; j++)

        {
            if (i % 2 == 0)
            {
                cout << ch + 32;
            }
            else
            {
                cout << ch;
            }
        }
        cout << endl;
    }
    return 0;
}