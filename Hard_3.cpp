#include <iostream>
#include <string>
using namespace std;

class Person 
{
protected:
    const int id;
    string name;

public:
    Person(int i, string n) : id(i), name(n) {}

    virtual void displayInfo() const {
        cout << "Person's ID : " << id << endl;
        cout << "Person's Name : " << name << endl;
    }
};

class Student : virtual public Person
{
protected:
    float gpa;
    static int totalPersons;

public:
    Student(int id, string name, float g) 
        : Person(id, name), gpa(g) {
        totalPersons++;
    }

    void displayInfo() const override {
        cout << "Student's ID : " << id << endl;
        cout << "Student's Name : " << name << endl;
        cout << "Student's GPA : " << gpa << endl;
    }

    static void showTotalPersons() {
        cout << "Total Students : " << totalPersons << endl;
    }
};

int Student::totalPersons = 0;

class Teacher : virtual public Person
{
protected:
    string subject;

public:
    Teacher(int id, string name, string sub) 
        : Person(id, name), subject(sub) {}

    void displayInfo() const override {
        cout << "Teacher's ID : " << id << endl;
        cout << "Teacher's Name : " << name << endl;
        cout << "Teacher's Subject : " << subject << endl;
    }
};

class TeacherAssistant : public Student, public Teacher
{
public:
    TeacherAssistant(int i, string n, float g, string su)
        : Person(i, n), Student(i, n, g), Teacher(i, n, su) {}

    void displayInfo() const override {
        cout << "Teacher Assistant's ID : " << id << endl;
        cout << "Teacher Assistant's Name : " << name << endl;
        cout << "Teacher Assistant's GPA : " << gpa << endl;
        cout << "Teacher Assistant's Subject : " << subject << endl;
    }
};

int main() 
{
    Student s1(101, "Ali", 3.5);
    Teacher t1(201, "Ahmed", "Math");
    TeacherAssistant ta1(301, "Sara", 3.8, "Physics");

    cout << "\n--- Student Info ---\n";
    s1.displayInfo();

    cout << "\n--- Teacher Info ---\n";
    t1.displayInfo();

    cout << "\n--- Teacher Assistant Info ---\n";
    ta1.displayInfo();

    cout << "\n--- Total Students ---\n";
    
    Student::showTotalPersons();

    return 0;
}