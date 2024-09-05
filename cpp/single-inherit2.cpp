#include <iostream>
using namespace std;
class batsman
{
private:
    int bcode;
    char name[20];
    int innings, notout, run;

public:
    int batavg;

    void getdata()
    {
        cout << "enter bcode=";
        cin >> bcode;

        cout << "enter name=";
        cin >> name;

        cout << "enter inning=";
        cin >> innings;

        cout << "enter notout=";
        cin >> notout;

        cout << "enter run=";
        cin >> run;

        cout << endl;
    }
    void display()
    {
        getdata();
        cout << "bcode=" << bcode << endl;
        cout << "name=" << name << endl;
        cout << "innings=" << innings << endl;
        cout << "notout=" << notout << endl;
        cout << "run=" << run << endl;
    }
};

class derive : public batsman
{
public:
    void displayalldata()
    {
        int innings, notout, run;

        display();
        batavg = run / (innings - notout);
        cout << "batavg=" << batavg << endl;
    }
};
int main()
{
    derive obj;
    obj.displayalldata();
}