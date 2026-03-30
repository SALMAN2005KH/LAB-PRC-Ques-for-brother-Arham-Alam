#include <iostream>
#include <string>
using namespace std;

class Passenger 
{
private:
    const int passId;
    string passName;
    static int totalPass;

public:
    Passenger(int id, string name) : passId(id), passName(name) {
        totalPass++;
    }

    ~Passenger() {
        cout << "Passenger's Data Removed" << endl;
    }

    void displayPassDetails() const {
        cout << "\n____Passenger Details___\n";
        cout << "Passenger Name : " << passName << endl;
        cout << "Passenger ID : " << passId << endl;
    }

    static void displayTotalPass() {
        cout << "Total Passengers : " << totalPass << endl;
    }
};

int Passenger::totalPass = 0;

class Flight 
{
private:
    const int flightId;
    string designation;
    Passenger passenger[5];
    static int totalFlight;

public:
    Flight(int id, string d) 
        : flightId(id),
          designation(d),
          passenger{
              Passenger(1, "Ali"),
              Passenger(2, "Sara"),
              Passenger(3, "Ahmed"),
              Passenger(4, "Zain"),
              Passenger(5, "Ayesha")
          }
    {
        totalFlight++;
    }

    ~Flight () {
        cout << "Flight Delayed." << endl;
    }

    void displayFlightDetails() const {
        cout << "\n___Flight Details___\n";
        cout << "Flight ID : " << flightId << endl;
        cout << "Designation : " << designation << endl;

        for (int i = 0; i < 5; i++) {
            passenger[i].displayPassDetails();
        }
    }

    
    void addPassenger(int index, int id, string name) {
        cout << "Cannot modify passenger (const data members)" << endl;
    }

    int countPassenger() const {
        return 5;
    }

    static void displayTotalFlights() {
        cout << "Total Flights : " << totalFlight << endl;
    }
};

int Flight::totalFlight = 0;

class AirlineSystem 
{
private:
    Flight flights[3];

public:
    AirlineSystem() 
        : flights{
            Flight(1, "Dubai"),
            Flight(2, "London"),
            Flight(3, "Istanbul")
        } 
    {}

    ~AirlineSystem() {   
        cout << "Airline System Crashed." << endl;
    }

    void displayFlightDetails() const {
        for(int i = 0; i < 3; i++) {
            flights[i].displayFlightDetails();
        }
    }

    void totalPassengersAllFlights() const {
        int total = 0;
        for(int i = 0; i < 3; i++) {
            total += flights[i].countPassenger();
        }
        cout << "\nTotal Passengers in All Flights: " << total << endl;
    }
};

int main () {
    AirlineSystem system;
   
    system.displayFlightDetails();
    
    system.totalPassengersAllFlights();

    cout << endl;
    Passenger::displayTotalPass();
    Flight::displayTotalFlights();

    return 0;
}