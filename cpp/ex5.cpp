#include<iostream>
using namespace std;
class report
{
  private:
    int adno;
    char name[20];
    float marks;
    float average;
    float sum = 0.0;
    float getavg();
    
  public:
    void readinfo()
    { 
        cout<<"enter name :";
        cin>>name;
        
        cout<<"enter adno :";
        cin>>adno;
        
        cout<<"marks :";
        cin>>marks;
        
        getavg();
        
        
    }
    void displayinfo()
    {
        cout<<"---------------------"<<endl;
        cout<<"name :"<<name<<endl;
        cout<<"adno :"<<adno<<endl;
        cout<<"marks :"<<marks<<endl;
        cout<<"average :"<<average<<endl;
        
    }
};

float report :: getavg()
{
    sum +=marks;
    return average=marks/5;
};

int main()
{
    class report obj;
    obj.readinfo();
    obj.displayinfo();
    
    return 0;
}