#include <iostream>
#include <string>
using namespace std;

class Vehicle 
{
protected:
    const int vehicleId;
    string brand;
    static int totalVehicles;

public:
    Vehicle(int Id, string br) : vehicleId(Id), brand(br) {
        totalVehicles++;
    }

    virtual ~Vehicle() {
        cout << "Vehicle Destroyed." << endl;
    }

    virtual void displayVehicles() const {
        cout << "Vehicle ID : " << vehicleId << endl;
        cout << "Vehicle Brand : " << brand << endl;
    }

    static void showTotalVehicles() {
        cout << "Total Vehicles: " << totalVehicles << endl;
    }
};

int Vehicle::totalVehicles = 0;

class Car : virtual public Vehicle
{
protected:
    int seats;

public:
    Car(int i, string b, int s) : Vehicle(i, b), seats(s) {}
    virtual ~Car() {
        cout << "Car Destroyed." << endl;
    }

    void displayVehicles() const override {
        cout << "Car ID : " << vehicleId << endl;
        cout << "Car Brand : " << brand << endl;
        cout << "Car Seats : " << seats << endl;
    }
};

class Truck : virtual public Vehicle
{
protected:
    float loadCapacity;

public:
    Truck(int i, string b, float lc) : Vehicle(i, b), loadCapacity(lc) {}
    virtual ~Truck() {
        cout << "Truck Destroyed." << endl;
    }

    void displayVehicles() const override {
        cout << "Truck ID : " << vehicleId << endl;
        cout << "Truck Brand : " << brand << endl;
        cout << "Truck Load Capacity : " << loadCapacity << " tons" << endl;
    }
};

class Electric
{
protected:
    int BatteryCapacity;

public:
    Electric(int BC) : BatteryCapacity(BC) {}
    void displayElectric() const {
        cout << "Battery Capacity : " << BatteryCapacity << " kWh" << endl;
    }
};

class ElectricCar : public Car, public Electric
{
public:
    ElectricCar(int i, string b, int s, int bc)
        : Vehicle(i, b), Car(i, b, s), Electric(bc) {}

    ~ElectricCar() {
        cout << "Electric Car Destroyed." << endl;
    }

    void displayVehicles() const override {
        cout << "Electric Car ID : " << vehicleId << endl;
        cout << "Electric Car Brand : " << brand << endl;
        cout << "Electric Car Seats : " << seats << endl;
        cout << "Electric Car Battery Capacity : " << BatteryCapacity << " kWh" << endl;
    }
};

int main()
{
    Vehicle* v[4];

    v[0] = new Car(1, "Toyota", 5);
    v[1] = new Truck(2, "Volvo", 10.5);
    v[2] = new ElectricCar(3, "Tesla", 5, 75);
    v[3] = new Car(4, "Honda", 4);

    cout << "===== Vehicle Data =====\n";
    for (int i = 0; i < 4; i++) {
        v[i]->displayVehicles();
        cout << endl;
    }

    // Static counter
    Vehicle::showTotalVehicles();

    // Cleanup
    for (int i = 0; i < 4; i++) {
        delete v[i];
    }

    return 0;
}