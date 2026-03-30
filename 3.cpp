#include <iostream>
#include <string>
using namespace std;

class Branch 
{
    private :
    const string BranchCode;
    string city;

    public :
    Branch(string bc, string c) : BranchCode(bc), city(c) {}

    void displayBranch() {
        cout << "\n_____Branch Details____\n";
        cout << "Branch Code : " << BranchCode << endl;
        cout << "City : " << city << endl;
    }
};

class Account 
{
    private :
    const int accNo;
    double balance;
    static int totalAcc;
    Branch* branch;

    public : 
    Account (int acc, double bal, Branch* b) : accNo(acc), balance(bal) {
        branch = b;
        totalAcc++;
    }
    ~Account () {
        cout << "Account Closed." << endl;
    }
    // Deposit Function
    void deposit(double amount) {
        balance += amount;
    }
    static void displayTotalAcc() {
        cout << "Total Accounts : " << totalAcc << endl;
    }
    void displayInfo() const {
        cout << "\n_____Account Details____\n";
        cout << "Account No. : " << accNo << endl;
        cout << "Balance : " << balance << endl;
        branch->displayBranch();
        cout << endl;
    }
};
int Account :: totalAcc = 0;
int main () {
    // Branch objects
    Branch b1("BR01", "Karachi");
    Branch b2("BR02", "Lahore");

    // Array of Account objects
    Account acc[4] = {
        Account(1001, 5000, &b1),
        Account(1002, 7000, &b2),
        Account(1003, 6000, &b1),
        Account(1004, 8000, &b2)
    };

    // Deposit amounts
    acc[0].deposit(1000);
    acc[1].deposit(500);
    acc[2].deposit(2000);
    acc[3].deposit(1500);

    for (int i=0; i<4; i++) {
        acc[i].displayInfo();
    }
 Account :: displayTotalAcc();
return 0;
}