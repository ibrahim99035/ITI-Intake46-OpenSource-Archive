#include <iostream>
#include <windows.h>

using namespace std;

void textattr(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

struct Student {
    string name;
    int age;
    float grade;
};

void printStudent(Student s);

int main(){
    cout<<"============================Student Information============================\n\n";

    while (true) {
        Student s;

        cout << "Student Name: ";
        cin >> s.name;

        cout << "Student Age: ";
        cin >> s.age;

        cout << "Student Grade: ";
        cin >> s.grade;

        printStudent(s);

        char choice;
        textattr(10);
        cout << "\n\nDo you want to override student info? (y/n): ";
        textattr(15);
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }
    return 0;
}

void printStudent(Student s) {
    cout << "\n===== Student Information =====\n";
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "Grade: " << s.grade << endl;
    cout << "=================================\n";
}