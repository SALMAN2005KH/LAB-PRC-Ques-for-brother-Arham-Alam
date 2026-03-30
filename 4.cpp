#include <iostream>
#include <string>
using namespace std;

class Department 
{
    private :
    const int deptId;
    string deptName;

    public : 
    Department (int id, string name) : deptId(id), deptName(name) {}

    void displayDept() {
        cout << "\n___Department Details___\n";
        cout << "Department ID : " << deptId << endl;
         cout << "Department Name : " << deptName << endl;
    }
};

class Employee 
{
    private : 
    const int empId;
    string empName;
    double salary;
    Department* dept;
    static int empCount;

    public :
    Employee (int id, string name, double sal, Department *d) : empId(id), empName(name), salary(sal) {
        dept = d;
        empCount++;
    }
    ~Employee(){
        cout << "Employee Removed." << endl;
    }
    static void totalEmp() {
        cout << "Total Employees : " << empCount << endl;
    }
    double IncreaseSalary() {
        double newsalary = salary * 1.1;
        return newsalary;
    }
    void displayEmpDetails() {
        cout << "\n___Employee Details___\n";
        cout << "Employee ID : " << empId << endl;
        cout << "Employee Name : " << empName << endl;
        cout << "Employee Salary (with 10% incremation) : " << IncreaseSalary() << endl;
        dept->displayDept();
    }
};
int Employee :: empCount = 0;

int main() {
   
    Department d1(1, "HR");
    Department d2(2, "IT");

    Employee emp[5] = {
        Employee(101, "Ali", 50000, &d1),
        Employee(102, "Ahmed", 60000, &d2),
        Employee(103, "Sara", 55000, &d1),
        Employee(104, "Ayesha", 65000, &d2),
        Employee(105, "Bilal", 70000, &d1)
    };

    for(int i = 0; i < 5; i++) {
        emp[i].IncreaseSalary();
    }

    cout << "\n--- Updated Employee Data ---\n";
    for(int i = 0; i < 5; i++) {
        emp[i].displayEmpDetails();
    }
    Employee :: totalEmp();
return 0;
}