#include <iostream>
#include <string>
using namespace std;

class Doctor
{
    private :
    const int docId;
    string special;

    public : 
    Doctor (int id, string ization) : docId(id), special(ization) {}
    void displayDoctorDetails() {
        cout << "\n___Doctor Details___\n";
        cout << "Doctor's ID : " << docId << endl;
        cout << "Specialization : " << special << endl;
    }
};

class Patient 
{
    private :
    const int patientID;
    string patientName;
    int age;
    Doctor* doc;
    static int totalPatients;

    public :
    Patient (int id, string name, int a, Doctor* d) : patientID(id), patientName(name), age(a) {
        doc = d;
        totalPatients++;
    }
    ~Patient() {
        cout << "Patient Discharged." << endl;
    }
    static void displayTotalPatients() {
        cout << "Total Patients : " << totalPatients << endl;
    }
    void displayPatientDetails() {
        cout << "\n___Patient Details___\n";
        cout << "Patient's ID : " << patientID << endl;
        cout << "Patient's Name : " << patientName << endl;
        cout << "Patient's Age : " << age << endl;
        doc->displayDoctorDetails();
    }
};
int Patient :: totalPatients = 0;
int main()
{
    Doctor d1(1, "Cardiologist");
    Doctor d2(2, "Neurologist");
    Doctor d3(3, "Orthopedic");
    Doctor d4(4, "Dermatologist");
    Doctor d5(5, "Pediatrician");

    Patient p[5] = {
        Patient(101, "Ali", 25, &d1),
        Patient(102, "Ahmed", 30, &d2),
        Patient(103, "Sara", 22, &d3),
        Patient(104, "Ayesha", 28, &d4),
        Patient(105, "Bilal", 10, &d5)
    };

    cout << "\n___Patient Records___\n";
    for(int i = 0; i < 5; i++) {
        p[i].displayPatientDetails();
    }

    Patient::displayTotalPatients();

    return 0;
}