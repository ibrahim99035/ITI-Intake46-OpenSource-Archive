#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void textattr(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

struct Employee {
    string name;
    int id;
    double salary;
};

void readEmployees(Employee employees[], int size);
void printEmployees(const Employee employees[], int size);

int main() {
    cout<<"===========================Employees Data===========================\n\n";

    int n;
    cout << "Number of Employees: ";
    cin >> n;

    Employee employees[n];
    readEmployees(employees, n);
    printEmployees(employees, n);

    return 0;
}

void readEmployees(Employee employees[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "\nEnter details for employee #" << i + 1 << ":\n";

        cout << "Name: ";
        cin>>employees[i].name;

        cout << "ID: ";
        cin >> employees[i].id;

        cout << "Salary: ";
        cin >> employees[i].salary;
    }
}

void printEmployees(const Employee employees[], int size) {
    cout << "\n=====================Employee Details=====================\n";
    for (int i = 0; i < size; i++) {
        textattr(9);
        cout << "\nEmployee #" << i + 1 << ":\n";
        cout << "Name: " << employees[i].name << endl;
        cout << "ID: " << employees[i].id << endl;
        cout << "Salary: " << employees[i].salary << endl;
    }
    textattr(15);
    cout << "\n======================End of Details======================";
}