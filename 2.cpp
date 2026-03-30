#include <iostream>
#include <string>
using namespace std;

class Course 
{
private:
    int courseID;              // removed const
    string courseName;

public:
    Course(int id = 0, string name = "") : courseID(id), courseName(name) {}

    void setCourse() {
        cout << "Enter Course ID : ";
        cin >> courseID;

        cout << "Enter Course Name : ";   
        cin >> courseName;
    }

    void displayCourse() const {
        cout << "Course ID : " << courseID << endl;
        cout << "Course Name : " << courseName << endl;
    }
};

class Student 
{
private:
    string stdName;
    static int totalStd;
    Course *course;

public:
    Student() {
        course = new Course();   // DMA
        totalStd++;
    }

    Student(string name, Course *c) {
        stdName = name;
        course = c;
        totalStd++;
    }

    void setStdDetails() {
        cout << "Enter Student's Name : ";
        cin >> stdName;

        course->setCourse();
    }

    ~Student() {
        delete course;   
        cout << "Student Record Deleted Successfully.\n";
    }

    void displayInfo() const {
        cout << "\n____Student Details___\n";
        cout << "Student's Name : " << stdName << endl;

        cout << "\n____Course Details____\n";
        course->displayCourse();
    }

    static void displayTotalStd(){
        cout << "Total Students : " << totalStd << endl;
    }
};

int Student :: totalStd = 0;

int main() 
{
    Student s[3];

    for (int i=0; i<3; i++) {
        s[i].setStdDetails();
    }

    for (int i=0; i<3; i++) {
        s[i].displayInfo();
    }

    Student::displayTotalStd();

    return 0;
}