#include <iostream>
using namespace std;

class Person {
protected:
    const int personID;
    string name;
    static int totalPersons;

public:
    Person(int id, string n) : personID(id), name(n) {
        totalPersons++;
    }

    virtual ~Person() {
        cout << "Person " << name << " destroyed\n";
    }

    virtual void display() const {
        cout << "Person ID: " << personID << endl;
        cout << "Name: " << name << endl;
    }

    static void showTotalPersons() {
        cout << "Total Persons: " << totalPersons << endl;
    }
};

int Person::totalPersons = 0;

class Passenger : public Person {
protected:
    int seatNumber;

public:
    Passenger(int id, string n, int seat)
        : Person(id, n), seatNumber(seat) {}

    virtual ~Passenger() {
        cout << "Passenger " << name << " removed\n";
    }

    void display() const override {
        Person::display();
        cout << "Seat Number: " << seatNumber << endl;
    }

    void displayInfo() const {
        cout << "Passenger Info (early binding): " << name << ", Seat " << seatNumber << endl;
    }
};

class Pilot : virtual public Person {
protected:
    int experienceYears;

public:
    Pilot(int id, string n, int exp)
        : Person(id, n), experienceYears(exp) {}

    virtual ~Pilot() {
        cout << "Pilot " << name << " removed\n";
    }

    void display() const override {
        Person::display();
        cout << "Experience: " << experienceYears << " years\n";
    }
};

class CrewMember : virtual public Person {
protected:
    string role;

public:
    CrewMember(int id, string n, string r)
        : Person(id, n), role(r) {}

    virtual ~CrewMember() {
        cout << "CrewMember " << name << " removed\n";
    }

    void display() const override {
        Person::display();
        cout << "Role: " << role << endl;
    }
};

class FlightStaff : public Pilot, public CrewMember {
public:
    FlightStaff(int id, string n, int exp, string r)
        : Person(id, n), Pilot(id, n, exp), CrewMember(id, n, r) {}

    virtual ~FlightStaff() {
        cout << "FlightStaff " << name << " removed\n";
    }

    void display() const override {
        Person::display();
        cout << "Experience: " << experienceYears << " years\n";
        cout << "Role: " << role << endl;
    }
};

class Flight {
    const int flightID;
    string destination;
    Passenger* passengers[3]; // pointers for polymorphism
    static int totalFlights;

public:
    Flight(int id, string dest, Passenger* p1, Passenger* p2, Passenger* p3)
        : flightID(id), destination(dest) {
        passengers[0] = p1;
        passengers[1] = p2;
        passengers[2] = p3;
        totalFlights++;
    }

    ~Flight() {
        cout << "Flight " << flightID << " to " << destination << " ended\n";
        // Clean up passengers if allocated dynamically
        for (int i = 0; i < 3; i++) {
            delete passengers[i];
        }
    }

    void display() const {
        cout << "Flight ID: " << flightID << endl;
        cout << "Destination: " << destination << endl;
        cout << "Passengers:\n";
        for (int i = 0; i < 3; i++) {
            passengers[i]->display();
            cout << endl;
        }
    }

    static void showTotalFlights() {
        cout << "Total Flights: " << totalFlights << endl;
    }
};

int Flight::totalFlights = 0;

int main() {

    Flight* flights[2];

    // Create passengers dynamically for polymorphism
    flights[0] = new Flight(101, "Karachi",
                             new Passenger(1, "Ali", 1),
                             new Passenger(2, "Sara", 2),
                             new Passenger(3, "Hina", 3));

    flights[1] = new Flight(102, "Lahore",
                             new Passenger(4, "Usman", 4),
                             new Passenger(5, "Ahmed", 5),
                             new Passenger(6, "Sana", 6));

    cout << "===== Display Flights (Early Binding) =====\n";
    flights[0]->display();
    cout << endl;
    flights[1]->display();
    cout << endl;

    Person* staff[3];
    staff[0] = new Pilot(7, "Captain Ali", 10);
    staff[1] = new CrewMember(8, "Hina", "Attendant");
    staff[2] = new FlightStaff(9, "Usman", 8, "Co-Pilot");

    cout << "===== Display Staff (Late Binding) =====\n";
    for (int i = 0; i < 3; i++) {
        staff[i]->display(); // virtual function → runtime polymorphism
        cout << endl;
    }

    Person::showTotalPersons();
    Flight::showTotalFlights();

    for (int i = 0; i < 3; i++) delete staff[i];
    for (int i = 0; i < 2; i++) delete flights[i];

    return 0;
}