#include <iostream>
using namespace std;
int main()
{
    char str1[100], str2[100];
    int i, j;

    cout << "str1";
    cin >> str1;
    cout << "str2";
    cin >> str2;

    for (i = 0; str1[i] != '\0'; i++)
    {
        for (j = 0; str2[j] != '\0'; j++)
        {
            str1[i] = str2[j];
            i++;
        }
        str1[i] = '\0';
    }
    cout << "concate=" << str1;
    return 0;
}