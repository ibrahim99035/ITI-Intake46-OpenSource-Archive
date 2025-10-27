#include <iostream>
using namespace std;

int main()
{
    cout << "================Grading System================" << endl;

    float degree;
    cout << "Enter your degree (0 - 100): ";
    cin >> degree;

    if (degree < 0 || degree > 100) {
        cout << "Invalid degree - Must be between 0 and 100." << endl;
        return 0;
    }

    float gpa;
    string symbol;

    if (degree >= 90) {
        gpa = 4.0;
        symbol = "A+";
    }
    else if (degree >= 85) {
        gpa = 3.7;
        symbol = "A";
    }
    else if (degree >= 80) {
        gpa = 3.3;
        symbol = "B+";
    }
    else if (degree >= 75) {
        gpa = 3.0;
        symbol = "B";
    }
    else if (degree >= 70) {
        gpa = 2.7;
        symbol = "C+";
    }
    else if (degree >= 65) {
        gpa = 2.4;
        symbol = "C";
    }
    else if (degree >= 60) {
        gpa = 2.0;
        symbol = "D+";
    }
    else if (degree >= 50) {
        gpa = 1.7;
        symbol = "D";
    }
    else {
        gpa = 0.0;
        symbol = "F";
    }

    cout<<"\n";
    cout << "Your GPA is " << gpa << " and your grade is " << symbol << endl;

    return 0;
}