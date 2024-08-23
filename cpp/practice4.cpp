#include <iostream>
using namespace std;
struct student
{
    int rollno, per, total, mark[3];
    char name[50];
};

int main()
{
    struct student s[5];

    for (int i = 1; i < 5; i++)
    {
        s[i].total = 0;
        cout << "name :" << endl;
        cin >> s[i].name;
        cout << "roll no :" << endl;
        cin >> s[i].rollno;
        for (int j = 0; j < 3; j++)
        {
            cout << "marks :" << endl;
            cin >> s[i].mark[j];
        }
        for (int j = 0; j <= 3; j++)
        {
            s[i].total += s[i].mark[j];
        }
        cout << "total :" << s[i].total << endl;
        s[i].per = s[i].total / 3;
        cout << "per :" << s[i].per << endl;
    }
    return 0;
}
