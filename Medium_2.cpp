#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    const int accNo;
    string holderName;
    static int totalAcc;

public:
    Account(int acc, string name) : accNo(acc), holderName(name) {
        totalAcc++;
    }

    virtual ~Account() {
        cout << "Account Closed." << endl;
    }

    void displayAccDetails() const {
        cout << "\n___Account Details___\n";
        cout << "Account No. : " << accNo << endl;
        cout << "Account Holder Name : " << holderName << endl;
    }

    virtual void showAccDetails() const {
        cout << "\n___Account Details___\n";
        cout << "Account No. : " << accNo << endl;
        cout << "Account Holder Name : " << holderName << endl;
    }

    static void showTotalAccounts() {
        cout << "Total Accounts : " << totalAcc << endl;
    }
};

int Account::totalAcc = 0;

class SavingAccount : public Account
{
protected:
    float interestRate;

public:
    SavingAccount(float rate, int acc, string name)
        : Account(acc, name), interestRate(rate) {}

    ~SavingAccount() {
        cout << "Saving Account Removed." << endl;
    }

    void showAccDetails() const override {
        cout << "\n___Saving Account Details___\n";
        cout << "Interest Rate : " << interestRate << endl;
        cout << "Account No. : " << accNo << endl;
        cout << "Account Holder Name : " << holderName << endl;
    }
};

class CurrentAccount : public Account
{
protected:
    float overdraftLimit;

public:
    CurrentAccount(float limit, int acc, string name)
        : Account(acc, name), overdraftLimit(limit) {}

    ~CurrentAccount() {
        cout << "Current Account Removed." << endl;
    }

    void showAccDetails() const override {
        cout << "\n___Current Account Details___\n";
        cout << "Overdraft Limit : " << overdraftLimit << endl;
        cout << "Account No. : " << accNo << endl;
        cout << "Account Holder Name : " << holderName << endl;
    }
};

int main() {
    Account* accounts[5];

    accounts[0] = new SavingAccount(5.5, 1, "Ali");
    accounts[1] = new CurrentAccount(10000, 2, "Ahmed");
    accounts[2] = new SavingAccount(4.2, 3, "Sara");
    accounts[3] = new CurrentAccount(20000, 4, "Hina");
    accounts[4] = new SavingAccount(6.0, 5, "Usman");

    // Base class function
    for (int i = 0; i < 5; i++) {
        accounts[i]->displayAccDetails();
    }

    // Polymorphism
    for (int j = 0; j < 5; j++) {
        accounts[j]->showAccDetails();
    }

    for (int k = 0; k < 5; k++) {
        delete accounts[k];
    }

    Account::showTotalAccounts();

    return 0;
}