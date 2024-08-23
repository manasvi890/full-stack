#include <iostream>
using namespace std;

int main()
{
    char str1[50], temp;
    int lenth = 0, i;
    cout << "enter string :";
    cin >> str1;
    for (i = 0; str1[i] != '\0'; i++)
    {
        lenth++;
    }
    cout << "lenth=" << lenth << endl;

    for (i = 0; i <= lenth / 2; i++)
    {
        temp = str1[i];
        str1[i] = str1[lenth - i - 1];
        str1[lenth - i - 1] = temp;
    }
    cout << "reverse :" << str1;

    return 0;
}
