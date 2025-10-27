#include <iostream>
#include <conio.h>
#include <windows.h>

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
};

class EmployeeStack {
    Employee* data;
    int stackSize;
    int tos;
public:
    EmployeeStack(int _size = 10) {
        stackSize = _size;
        data = new Employee[stackSize];
        tos = -1;
    }

    ~EmployeeStack() {
        delete[] data;
    }

    bool isEmpty() {
        return tos == -1;
    }

    bool isFull() {
        return tos == stackSize - 1;
    }

    void push(Employee emp) {
        if(!isFull()) {
            tos++;
            data[tos] = emp;
            textattr(10);
            cout<<"\nEmployee successfully added to stack!\n";
            textattr(7);
        } else {
            textattr(12);
            cout<<"\nSTACK OVERFLOW! Cannot add more employees.\n";
            textattr(7);
        }
    }

    Employee pop() {
        Employee emp;
        if(!isEmpty()) {
            emp = data[tos];
            tos--;
            return emp;
        } else {
            textattr(12);
            cout<<"\nSTACK IS EMPTY! No employees to display.\n";
            textattr(7);
            emp.name = "";
            emp.id = -1;
            emp.salary = 0;
            return emp;
        }
    }

    Employee peek() {
        Employee emp;
        if(!isEmpty()) {
            return data[tos];
        } else {
            textattr(12);
            cout<<"\nSTACK IS EMPTY! No top employee.\n";
            textattr(7);
            emp.name = "";
            emp.id = -1;
            emp.salary = 0;
            return emp;
        }
    }

    void displayAll() {
        if(isEmpty()) {
            textattr(12);
            cout<<"\nSTACK IS EMPTY! No employees to display.\n";
            textattr(7);
            return;
        }
        cout<<"\n=====================All Employees in Stack=====================\n";
        for(int i = tos; i >= 0; i--) {
            textattr(9);
            cout<<"\nPosition "<<(tos - i)<<" from top:\n";
            cout<<"Name: "<<data[i].name<<endl;
            cout<<"ID: "<<data[i].id<<endl;
            cout<<"Salary: "<<data[i].salary<<endl;
        }
        textattr(15);
        cout<<"\n======================End of Stack======================\n";
        cout<<"Total employees: "<<(tos + 1)<<endl;
        textattr(7);
    }

    int getCount() {
        return tos + 1;
    }
};

void MainMenu(EmployeeStack &stack);
void addEmployee(EmployeeStack &stack);
void displayEmployee(EmployeeStack &stack);
void peekEmployee(EmployeeStack &stack);
void checkEmpty(EmployeeStack &stack);
void checkFull(EmployeeStack &stack);
void displayAllEmployees(EmployeeStack &stack);

int main() {
    int stackSize;
    cout<<"Enter the maximum number of employees: ";
    cin>>stackSize;

    EmployeeStack stack(stackSize);
    MainMenu(stack);

    return 0;
}

void MainMenu(EmployeeStack &stack) {
    string names[7] = {"Add Employee", "Display Top Employee", "Peek Top Employee", "Display All Employees", "Check if Empty", "Check if Full", "Exit"};
    int index = 0;
    char ch;

    do {
        system("cls");
        for(int i = 0; i < 7; i++) {
            if(i == index) {
                textattr(160);
                gotoxy(10, 5 + i);
                cout<<names[i];
                textattr(7);
            } else {
                gotoxy(10, 5 + i);
                cout<<names[i];
            }
        }

        ch = getch();
        if(ch == -32) {
            ch = getch();
            switch(ch) {
                case 72:
                    index--;
                    if(index < 0) index = 6;
                    break;
                case 80:
                    index++;
                    if(index > 6) index = 0;
                    break;
            }
        }

        if(ch == 13) {
            system("cls");
            switch(index) {
                case 0:
                    cout<<"================Add New Employee================\n";
                    addEmployee(stack);
                    break;
                case 1:
                    cout<<"================Display Top Employee================\n";
                    displayEmployee(stack);
                    break;
                case 2:
                    cout<<"================Peek Top Employee================\n";
                    peekEmployee(stack);
                    break;
                case 3:
                    cout<<"================Display All Employees================\n";
                    displayAllEmployees(stack);
                    break;
                case 4:
                    checkEmpty(stack);
                    break;
                case 5:
                    checkFull(stack);
                    break;
                case 6:
                    cout<<"Exiting Program\n";
                    return;
            }
            _getch();
        }
    } while(ch != 27);

    cout<<"Exiting Program\n";
}

void addEmployee(EmployeeStack &stack) {
    char choice;
    do {
        if(stack.isFull()) {
            textattr(12);
            cout<<"\nSTACK IS FULL! Cannot add more employees.\n";
            textattr(7);
            break;
        }

        Employee emp;
        cout<<"\nEnter employee details:\n";
        cout<<"Name: ";
        cin>>emp.name;
        cout<<"ID: ";
        cin>>emp.id;
        cout<<"Salary: ";
        cin>>emp.salary;

        stack.push(emp);

        cout<<"\nAdd another employee? (y/n): ";
        cin>>choice;

    } while(choice == 'y' || choice == 'Y');
}

void displayEmployee(EmployeeStack &stack) {
    if(stack.isEmpty()) {
        return;
    }

    Employee emp = stack.pop();

    cout<<"\n=====================Employee Details=====================\n";
    textattr(9);
    cout<<"\nEmployee (Removed from Stack):\n";
    cout<<"Name: "<<emp.name<<endl;
    cout<<"ID: "<<emp.id<<endl;
    cout<<"Salary: "<<emp.salary<<endl;
    textattr(15);
    cout<<"\n======================End of Details======================\n";
    textattr(7);
}

void peekEmployee(EmployeeStack &stack) {
    Employee emp = stack.peek();

    if(emp.id == -1) {
        return;
    }

    cout<<"\n=====================Top Employee Details=====================\n";
    textattr(11);
    cout<<"\nTop Employee (Still in Stack):\n";
    cout<<"Name: "<<emp.name<<endl;
    cout<<"ID: "<<emp.id<<endl;
    cout<<"Salary: "<<emp.salary<<endl;
    textattr(15);
    cout<<"\n======================End of Details======================\n";
    textattr(7);
}

void checkEmpty(EmployeeStack &stack) {
    if(stack.isEmpty()) {
        textattr(14);
        cout<<"\nStack is EMPTY!\n";
        textattr(7);
    } else {
        textattr(10);
        cout<<"\nStack is NOT empty. Contains "<<stack.getCount()<<" employee(s).\n";
        textattr(7);
    }
}

void checkFull(EmployeeStack &stack) {
    if(stack.isFull()) {
        textattr(12);
        cout<<"\nStack is FULL! Cannot add more employees.\n";
        textattr(7);
    } else {
        textattr(10);
        cout<<"\nStack is NOT full. Can add more employees.\n";
        textattr(7);
    }
}

void displayAllEmployees(EmployeeStack &stack) {
    stack.displayAll();
}