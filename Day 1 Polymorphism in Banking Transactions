#include <iostream>
#include <string>
using namespace std;

// Base class: Account
class Account {
protected:
    int balance;

public:
    Account(int b) : balance(b) {}
    virtual void calculateInterest() = 0; // Pure virtual function
};

// Derived class: SavingsAccount
class SavingsAccount : public Account {
private:
    double rate;
    int time;

public:
    SavingsAccount(int b, double r, int t) : Account(b), rate(r), time(t) {}

    void calculateInterest() override {
        double interest = (balance * rate * time) / 100;
        cout << "Savings Account Interest: " << interest << endl;
    }
};

// Derived class: CurrentAccount
class CurrentAccount : public Account {
private:
    int maintenanceFee;

public:
    CurrentAccount(int b, int fee) : Account(b), maintenanceFee(fee) {}

    void calculateInterest() override {
        int newBalance = balance - maintenanceFee;
        cout << "Balance after fee deduction: " << newBalance << endl;
    }
};

int main() {
    int accountType;
    cout << "Enter Account Type (1 for Savings, 2 for Current): ";
    cin >> accountType;

    if (accountType == 1) {
        int balance, time;
        double rate;

        cout << "Enter Balance: ";
        cin >> balance;
        cout << "Enter Interest Rate (in percentage): ";
        cin >> rate;
        cout << "Enter Time (in years): ";
        cin >> time;

        if (balance < 1000 || balance > 1000000 || rate < 1 || rate > 15 || time < 1 || time > 10) {
            cout << "Invalid input.\n";
            return 1;
        }

        SavingsAccount savings(balance, rate, time);
        savings.calculateInterest();

    } else if (accountType == 2) {
        int balance, fee;

        cout << "Enter Balance: ";
        cin >> balance;
        cout << "Enter Monthly Maintenance Fee: ";
        cin >> fee;

        if (balance < 1000 || balance > 1000000 || fee < 50 || fee > 500) {
            cout << "Invalid input.\n";
            return 1;
        }

        CurrentAccount current(balance, fee);
        current.calculateInterest();

    } else {
        cout << "Invalid account type.\n";
    }

    return 0;
}
