#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textattr(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

struct Employee {
    string name;
    int id;
    double salary;
    bool occupied;
};

void addEmployee(Employee employees[], int size);
void displayMenu(Employee employees[], int size);
void displayAllEmployees(const Employee employees[], int size);
void displayByIndex(const Employee employees[], int size);

int main() {
    string names[3] = { "Add Employee", "Display Employees", "Exit" };
    int index = 0;
    char ch;
    Employee employees[50];

    // Initialize all employees as unoccupied
    for (int i = 0; i < 50; i++) {
        employees[i].occupied = false;
    }

    do {
        system("cls");
        for (int i = 0; i < 3; i++) {
            if (i == index) {
                textattr(0xA0);
                gotoxy(10, 5 + i);
                cout << names[i];
                textattr(0x07);
            } else {
                gotoxy(10, 5 + i);
                cout << names[i];
            }
        }

        ch = getch();
        if (ch == -32) {
            ch = getch();
            switch (ch) {
                case 72:
                    index--;
                    if (index < 0) index = 2;
                    break;
                case 80:
                    index++;
                    if (index > 2) index = 0;
                    break;
            }
        }

        if (ch == 13) {
            system("cls");
            switch (index) {
                case 0:
                    cout << "================Add New Employee================\n";
                    addEmployee(employees, 50);
                    break;
                case 1:
                    displayMenu(employees, 50);
                    break;
                case 2:
                    cout << "Exiting Program\n";
                    return 0;
            }
            getch();
        }
    } while (ch != 27);

    cout << "Exiting Program\n";
    return 0;
}

void addEmployee(Employee employees[], int size) {
    char choice;
    do {
        int desiredIndex;
        cout << "\nEnter the index (0-" << size - 1 << ") where you want to add the employee: ";
        cin >> desiredIndex;

        if (desiredIndex < 0 || desiredIndex >= size) {
            cout << "Invalid index! Please enter a value between 0 and " << size - 1 << endl;
            cout << "Try again? (y/n): ";
            cin >> choice;
            continue;
        }

        // Check if index is occupied
        if (employees[desiredIndex].occupied) {
            textattr(12); // Red color
            cout << "\nWARNING: Index " << desiredIndex << " is already occupied!\n";
            cout << "Current data:\n";
            cout << "Name: " << employees[desiredIndex].name << endl;
            cout << "ID: " << employees[desiredIndex].id << endl;
            cout << "Salary: " << employees[desiredIndex].salary << endl;
            textattr(14); // Yellow color
            cout << "\nDo you want to override this data? (y/n): ";
            textattr(0x07); // Reset color
            char override;
            cin >> override;

            if (override != 'y' && override != 'Y') {
                cout << "Operation cancelled.\n";
                cout << "Add another employee? (y/n): ";
                cin >> choice;
                continue;
            }
        }

        // Add employee
        cout << "\nEnter details for employee at index " << desiredIndex << ":\n";
        cout << "Name: ";
        cin >> employees[desiredIndex].name;
        cout << "ID: ";
        cin >> employees[desiredIndex].id;
        cout << "Salary: ";
        cin >> employees[desiredIndex].salary;
        employees[desiredIndex].occupied = true;

        textattr(10); // Green color
        cout << "\nEmployee successfully added at index " << desiredIndex << "!\n";
        textattr(0x07); // Reset color

        cout << "Add another employee? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
}

void displayMenu(Employee employees[], int size) {
    string options[2] = { "Display All Real Data", "Display by Index" };
    int index = 0;
    char ch;

    do {
        system("cls");
        cout << "================Display Employees================\n\n";

        for (int i = 0; i < 2; i++) {
            if (i == index) {
                textattr(0xA0);
                gotoxy(10, 5 + i);
                cout << options[i];
                textattr(0x07);
            } else {
                gotoxy(10, 5 + i);
                cout << options[i];
            }
        }

        ch = getch();
        if (ch == -32) {
            ch = getch();
            switch (ch) {
                case 72:
                    index--;
                    if (index < 0) index = 1;
                    break;
                case 80:
                    index++;
                    if (index > 1) index = 0;
                    break;
            }
        }

        if (ch == 13) {
            system("cls");
            switch (index) {
                case 0:
                    displayAllEmployees(employees, size);
                    return;
                case 1:
                    displayByIndex(employees, size);
                    return;
            }
        }

    } while (ch != 27);
}

void displayAllEmployees(const Employee employees[], int size) {
    cout << "================Display All Real Data================\n";

    int count = 0;
    for (int i = 0; i < size; i++) {
        if (employees[i].occupied) {
            count++;
        }
    }

    if (count == 0) {
        cout << "\n\nNo employees to display!\n";
        return;
    }

    cout << "\n=====================Employee Details=====================\n";
    for (int i = 0; i < size; i++) {
        if (employees[i].occupied) {
            textattr(9);
            cout << "\nEmployee at Index " << i << ":\n";
            cout << "Name: " << employees[i].name << endl;
            cout << "ID: " << employees[i].id << endl;
            cout << "Salary: " << employees[i].salary << endl;
        }
    }
    textattr(15);

    cout << "\n======================End of Details======================\n";
    cout << "Total employees: " << count << endl;
}

void displayByIndex(const Employee employees[], int size) {
    cout << "================Display by Index================\n";

    cout << "\nOccupied indices: ";
    bool foundAny = false;

    for (int i = 0; i < size; i++) {
        if (employees[i].occupied) {
            textattr(10);
            cout << i << " ";
            foundAny = true;
        }
    }
    textattr(0x07);

    if (!foundAny) {
        cout << "\n\nNo employees to display!\n";
        return;
    }

    cout << "\n\nEnter the index to display: ";
    int index;
    cin >> index;

    if (index < 0 || index >= size) {
        textattr(12);
        cout << "\nInvalid index!\n";
        textattr(0x07);
        return;
    }

    if (!employees[index].occupied) {
        textattr(14);
        cout << "\nNo employee data at index " << index << "!\n";
        textattr(0x07);
        return;
    }

    cout << "\n=====================Employee Details=====================\n";
    textattr(9);
    cout << "\nEmployee at Index " << index << ":\n";
    cout << "Name: " << employees[index].name << endl;
    cout << "ID: " << employees[index].id << endl;
    cout << "Salary: " << employees[index].salary << endl;
    textattr(15);
    cout << "\n======================End of Details======================\n";
}