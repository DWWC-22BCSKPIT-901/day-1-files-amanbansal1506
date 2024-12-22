#include <iostream>
#include <string>
using namespace std;

// Base class: Employee
class Employee {
protected:
    string name;
    int id;
    int salary;

public:
    Employee(string n, int i, int s) : name(n), id(i), salary(s) {}

    virtual void display() {
        cout << "Employee: " << name << " (ID: " << id << ")\n";
        cout << "Base Salary: " << salary << "\n";
    }

    virtual int calculateTotalEarnings() = 0; // Pure virtual function
};

// Derived class: Manager
class Manager : public Employee {
private:
    int rating;

public:
    Manager(string n, int i, int s, int r) : Employee(n, i, s), rating(r) {}

    int calculateBonus() {
        return (rating * 0.1 * salary);
    }

    int calculateTotalEarnings() override {
        return salary + calculateBonus();
    }

    void display() override {
        Employee::display();
        cout << "Role: Manager\n";
        cout << "Bonus: " << calculateBonus() << "\n";
        cout << "Total Earnings: " << calculateTotalEarnings() << "\n";
    }
};

// Derived class: Developer
class Developer : public Employee {
private:
    int extraHours;

public:
    Developer(string n, int i, int s, int h) : Employee(n, i, s), extraHours(h) {}

    int calculateOvertime() {
        return extraHours * 500;
    }

    int calculateTotalEarnings() override {
        return salary + calculateOvertime();
    }

    void display() override {
        Employee::display();
        cout << "Role: Developer\n";
        cout << "Overtime Compensation: " << calculateOvertime() << "\n";
        cout << "Total Earnings: " << calculateTotalEarnings() << "\n";
    }
};

int main() {
    int employeeType;
    cout << "Enter Employee Type (1 for Manager, 2 for Developer): ";
    cin >> employeeType;

    if (employeeType == 1) {
        string name;
        int id, salary, rating;

        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Performance Rating (1-5): ";
        cin >> rating;

        if (rating < 1 || rating > 5 || salary < 10000 || salary > 1000000) {
            cout << "Invalid input.\n";
            return 1;
        }

        Manager manager(name, id, salary, rating);
        manager.display();

    } else if (employeeType == 2) {
        string name;
        int id, salary, extraHours;

        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Extra Hours Worked: ";
        cin >> extraHours;

        if (extraHours < 0 || extraHours > 100 || salary < 10000 || salary > 1000000) {
            cout << "Invalid input.\n";
            return 1;
        }

        Developer developer(name, id, salary, extraHours);
        developer.display();

    } else {
        cout << "Invalid employee type.\n";
    }
    return 0;
}
