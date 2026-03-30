#include <iostream>
#include <string>
using namespace std;

class Patient
{
    private :
    const int patientId;
    string patientName;
    int age;
    static int totalPatients;

    public :
    Patient(int id, string name, int a) : patientId(id), patientName(name), age(a) {}
    ~Patient() {
        cout << "Patient Data Removed." << endl;
    }
    int getAge() const {
        return age;
    }
    void displayPatientDetails() const {
        cout << "\n___Patient Details___\n";
        cout << "Patient's ID : " << patientId << endl;
        cout << "Patient's Name : " << patientName << endl;
        cout << "Patient's Age : " << age << endl;
    }
    static void displayTotalPatients() {
        cout << "Total Patients : " << totalPatients << endl;
    }
};
int Patient :: totalPatients = 0;
class Hospital 
{
    private :
    Patient patient[5];

    public :
    Hospital() : patient{ Patient(101, "Ali", 19), Patient(102, "Arjun", 20), Patient(103, "Ahmed", 21), Patient(104, "Ankit", 24), Patient(105, "Aanil", 25),} {}

    ~Hospital() {
        cout << "Hospital Destroyed." << endl;
    }

    void findOldest() const {
        int maxIndex = 0;

        for(int i = 1; i < 5; i++) {
            if(patient[i].getAge() > patient[maxIndex].getAge()) {
                maxIndex = i;
            }
        }

        cout << "\n--- Oldest Patient ---\n";
        patient[maxIndex].displayPatientDetails();
    }
    void displayHospitalDetials() const {
        for (int i = 0; i < 5; i++)
        {
            patient[i].displayPatientDetails();
        }
        
    }
};

int main() {
    Hospital h;
    h.displayHospitalDetials();
    Patient :: displayTotalPatients();

return 0;
}