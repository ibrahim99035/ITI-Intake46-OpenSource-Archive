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

void MainMenu(Employee employees[], int DBSize);
void addEmployee(Employee employees[], int DBSize);
void SubMenu(Employee employees[], int DBSize);
void displayAllEmployees(const Employee employees[], int DBSize);
void displayByIndex(const Employee employees[], int DBSize);
void displayByName(const Employee employees[], int DBSize);
void editEmployee(Employee employees[], int DBSize);
void deleteEmployee(Employee employees[], int DBSize);

int main() {
    int DBSize;
    cout << "The Size of Your Database: ";
    cin >> DBSize;

    Employee *employees = new Employee[DBSize];

    for (int i = 0; i < DBSize; i++) {
        employees[i].occupied = false;
    }

    MainMenu(employees, DBSize);

    delete[] employees;

    return 0;
}

void MainMenu(Employee employees[], int DBSize) {
    string names[6] = { "Add Employee", "Display Employees", "Search", "Edit Employee", "Delete Employee", "Exit" };
    int index = 0;
    char ch;

    do {
        system("cls");
        for (int i = 0; i < 6; i++) {
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
                    if (index < 0) index = 5;
                    break;
                case 80:
                    index++;
                    if (index > 5) index = 0;
                    break;
            }
        }

        if (ch == 13) {
            system("cls");
            switch (index) {
                case 0:
                    cout << "================Add New Employee================\n";
                    addEmployee(employees, DBSize);
                    break;
                case 1:
                    displayAllEmployees(employees, DBSize);
                    break;
                case 2:
                    SubMenu(employees, DBSize);
                    break;
                case 3:
                    cout << "================Edit Employee================\n";
                    editEmployee(employees, DBSize);
                    break;
                case 4:
                    cout << "================Delete Employee================\n";
                    deleteEmployee(employees, DBSize);
                    break;
                case 5:
                    cout << "Exiting Program\n";
                    return;
            }
            getch();
        }
    } while (ch != 27);

    cout << "Exiting Program\n";
}

void addEmployee(Employee employees[], int DBSize) {
    char choice;
    do {
        int desiredIndex;
        cout << "\nEnter the index (0-" << DBSize - 1 << ") where you want to add the employee: ";
        cin >> desiredIndex;

        if (desiredIndex < 0 || desiredIndex >= DBSize) {
            cout << "Invalid index! Please enter a value between 0 and " << DBSize - 1 << endl;
            cout << "Try again? (y/n): ";
            cin >> choice;
            continue;
        }

        if (employees[desiredIndex].occupied) {
            textattr(12);
            cout << "\nWARNING: Index " << desiredIndex << " is already occupied!\n";
            cout << "Current data:\n";
            cout << "Name: " << employees[desiredIndex].name << endl;
            cout << "ID: " << employees[desiredIndex].id << endl;
            cout << "Salary: " << employees[desiredIndex].salary << endl;
            textattr(14);
            cout << "\nDo you want to override this data? (y/n): ";
            textattr(0x07);
            char override;
            cin >> override;

            if (override != 'y' && override != 'Y') {
                cout << "Operation cancelled.\n";
                cout << "Add another employee? (y/n): ";
                cin >> choice;
                continue;
            }
        }

        cout << "\nEnter details for employee at index " << desiredIndex << ":\n";
        cout << "Name: ";
        cin >> employees[desiredIndex].name;
        cout << "ID: ";
        cin >> employees[desiredIndex].id;
        cout << "Salary: ";
        cin >> employees[desiredIndex].salary;
        employees[desiredIndex].occupied = true;

        textattr(10);
        cout << "\nEmployee successfully added at index " << desiredIndex << "!\n";
        textattr(0x07);

        cout << "Add another employee? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
}

void SubMenu(Employee employees[], int DBSize) {
    string options[2] = { "Search By Name", "Search by Index" };
    int index = 0;
    char ch;

    do {
        system("cls");
        cout << "================Search Employees================\n\n";

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
                    displayByName(employees, DBSize);
                    return;
                case 1:
                    displayByIndex(employees, DBSize);
                    return;
            }
        }

    } while (ch != 27);
}

void displayAllEmployees(const Employee employees[], int DBSize) {
    cout << "================Display All Real Data================\n";

    int count = 0;
    for (int i = 0; i < DBSize; i++) {
        if (employees[i].occupied) {
            count++;
        }
    }

    if (count == 0) {
        cout << "\n\nNo employees to display!\n";
        return;
    }

    cout << "\n=====================Employee Details=====================\n";
    for (int i = 0; i < DBSize; i++) {
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

void displayByIndex(const Employee employees[], int DBSize) {
    cout << "================Search by Index================\n";

    cout << "\nOccupied indices: ";
    bool foundAny = false;

    for (int i = 0; i < DBSize; i++) {
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

    if (index < 0 || index >= DBSize) {
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

void displayByName(const Employee employees[], int DBSize) {
    cout << "================Search by Name================\n";

    cout << "\nOccupied indices: ";
    bool foundAny = false;

    for (int i = 0; i < DBSize; i++) {
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

    cout << "\n\nEnter the Name to search: ";
    string name;
    cin >> name;

    bool found = false;
    for (int i = 0; i < DBSize; i++) {
        if (employees[i].occupied && employees[i].name == name) {
            cout << "\n=====================Employee Details=====================\n";
            textattr(9);
            cout << "\nEmployee with the name " << name << " at Index " << i << ":\n";
            cout << "Name: " << employees[i].name << endl;
            cout << "ID: " << employees[i].id << endl;
            cout << "Salary: " << employees[i].salary << endl;
            textattr(15);
            cout << "\n======================End of Details======================\n";
            found = true;
            break;
        }
    }

    if (!found) {
        textattr(12);
        cout << "\n404 Employee Not Found!\n";
        textattr(0x07);
    }
}

void editEmployee(Employee employees[], int DBSize) {
    char choice;
    do {
        int desiredIndex;
        cout << "\nOccupied indices: ";
        bool foundAny = false;
        for (int i = 0; i < DBSize; i++) {
            if (employees[i].occupied) {
                textattr(10);
                cout << i << " ";
                foundAny = true;
            }
        }
        textattr(0x07);
        if (!foundAny) {
            cout << "\n\nNo employees to Edit!\n";
            return;
        }
        cout << "\n\nEnter the index (0-" << DBSize - 1 << ") where you want to Edit an employee: ";
        cin >> desiredIndex;
        if (desiredIndex < 0 || desiredIndex >= DBSize) {
            cout << "Invalid index! Please enter a value between 0 and " << DBSize - 1 << endl;
            cout << "Try again? (y/n): ";
            cin >> choice;
            continue;
        }
        if (!employees[desiredIndex].occupied) {
            textattr(12);
            cout << "\nNo Employee at this index!\n";
            textattr(0x07);
            cout << "Try again? (y/n): ";
            cin >> choice;
            continue;
        }
        textattr(9);
        cout << "\nCurrent data:\n";
        cout << "Name: " << employees[desiredIndex].name << endl;
        cout << "ID: " << employees[desiredIndex].id << endl;
        cout << "Salary: " << employees[desiredIndex].salary << endl;
        textattr(14);
        cout << "\nAre you sure you want to Edit this data? (y/n): ";
        textattr(0x07);
        char override;
        cin >> override;
        if (override != 'y' && override != 'Y') {
            cout << "Operation cancelled.\n";
            cout << "Edit another employee? (y/n): ";
            cin >> choice;
            continue;
        }
        cout << "\nEnter new details for employee at index " << desiredIndex << ":\n";
        cout << "Name: ";
        cin >> employees[desiredIndex].name;
        cout << "ID: ";
        cin >> employees[desiredIndex].id;
        cout << "Salary: ";
        cin >> employees[desiredIndex].salary;
        textattr(10);
        cout << "\nEmployee successfully Edited at index " << desiredIndex << "!\n";
        textattr(0x07);
        cout << "Edit another employee? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

void deleteEmployee(Employee employees[], int DBSize) {
    char choice;
    do {
        int desiredIndex;
        cout << "\nOccupied indices: ";
        bool foundAny = false;
        for (int i = 0; i < DBSize; i++) {
            if (employees[i].occupied) {
                textattr(10);
                cout << i << " ";
                foundAny = true;
            }
        }
        textattr(0x07);
        if (!foundAny) {
            cout << "\n\nNo employees to Delete!\n";
            return;
        }
        cout << "\n\nEnter the index (0-" << DBSize - 1 << ") where you want to Delete an employee: ";
        cin >> desiredIndex;
        if (desiredIndex < 0 || desiredIndex >= DBSize) {
            cout << "Invalid index! Please enter a value between 0 and " << DBSize - 1 << endl;
            cout << "Try again? (y/n): ";
            cin >> choice;
            continue;
        }
        if (!employees[desiredIndex].occupied) {
            textattr(12);
            cout << "\nNo Employee at this index!\n";
            textattr(0x07);
            cout << "Try again? (y/n): ";
            cin >> choice;
            continue;
        }
        textattr(9);
        cout << "\nEmployee to be deleted:\n";
        cout << "Name: " << employees[desiredIndex].name << endl;
        cout << "ID: " << employees[desiredIndex].id << endl;
        cout << "Salary: " << employees[desiredIndex].salary << endl;
        textattr(12);
        cout << "\nWARNING: Are you sure you want to DELETE this employee? (y/n): ";
        textattr(0x07);
        char confirm;
        cin >> confirm;
        if (confirm != 'y' && confirm != 'Y') {
            cout << "Operation cancelled.\n";
            cout << "Delete another employee? (y/n): ";
            cin >> choice;
            continue;
        }
        employees[desiredIndex].name = "";
        employees[desiredIndex].id = 0;
        employees[desiredIndex].salary = 0.0;
        employees[desiredIndex].occupied = false;
        textattr(10);
        cout << "\nEmployee successfully deleted at index " << desiredIndex << "!\n";
        textattr(0x07);
        cout << "Delete another employee? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}
