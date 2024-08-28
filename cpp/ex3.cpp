#include <iostream>

using namespace std;

class Flight
{
private:
    int FlightNumber;
    char Destination[50];
    float Distance;
    float Fuel;

    void CALFUEL()
    {
        if (Distance <= 1000)
        {
            Fuel = 500;
        }
        else if (Distance <= 2000)
        {
            Fuel = 1100;
        }
        else
        {
            Fuel = 2200;
        }
    }

public:
    void FEEDINFO()
    {

        cout << "Enter Destination: ";
        gets(Destination);

        cout << "Enter Flight Number: ";
        cin >> FlightNumber;

        cout << "Enter Distance: ";
        cin >> Distance;

        CALFUEL();
    }

    void SHOWINFO()
    {
        cout << "Flight Number: " << FlightNumber << endl;
        cout << "Destination: " << Destination << endl;
        cout << "Distance: " << Distance << endl;
        cout << "Fuel: " << Fuel << endl;
    }
};

int main()
{
    class Flight flight;
    flight.FEEDINFO();
    flight.SHOWINFO();
    return 0;
}