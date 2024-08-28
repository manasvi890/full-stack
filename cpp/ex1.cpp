#include<iostream>
using namespace std;
class batsman
{
  private:
     int bcode;
     char name[20];
     int innings,notout,run;
     int batavg;
     
     void calcavg();
    
     
  public:
     void readdata()
     {
         cout<<"enter bcode :";
         cin>>bcode;
         
         cout<<"enter batsman name :";
         cin>>name;
         
         cout<<"enter innings :";
         cin>>innings;
         
         cout<<"enter notout :";
         cin>>notout;
         
         cout<<"enter runs :";
         cin>>run;
         
        calcavg();
       
     }
     void display()
     {
         cout<<"batsman code :"<<bcode<<endl;
         cout<<"batsman name :"<<name<<endl;
         cout<<"batsman innings :"<<innings<<endl;
         cout<<"batsman notout :"<<notout<<endl;
         cout<<"batsman runs :"<<run<<endl;
         cout<<"batavg :"<<batavg<<endl;
     }
};
void batsman::calcavg()
{
    batavg =run/(innings-notout);
};
int main()
{
    class batsman obj;
    obj.readdata();
    obj.display();
    
    return 0;
}