#include <iostream>
#include <string>
using namespace std;

class Student 
{
    private :
    const int rollNo;
    string stdName;
    static int totalStd;

    public :
    Student(int roll, string name) : rollNo(roll) , stdName(name) {
        totalStd++;
    }
    ~Student() {
        cout << "Student Record Deleted." << endl;
    }
    void displayStdDetails() const {
        cout << "\n___Student Details___\n";
        cout << "Student Name : " << stdName << endl;
        cout << "Student Roll No. : " << rollNo << endl;
    }
    static void displayTotalStudents() {
        cout << "Total Students : " << totalStd << endl;
    } 
};
int Student :: totalStd = 0;

class Classroom 
{
    private :
    Student std[3];

    public :
    Classroom () : std { Student(1, "Ali"), Student(2, "Anus"), Student(3, "Ahmed") } {}
    void displayClassInfo() const {
        for (int i = 0; i < 3; i++)
        {
            std[i].displayStdDetails();
        }     
    }
    ~Classroom() {
        cout << "Classroom destroyed " << endl;
    }
};
int main () 
{
    Classroom c1;
    c1.displayClassInfo();
    Student :: displayTotalStudents();
return 0;
}