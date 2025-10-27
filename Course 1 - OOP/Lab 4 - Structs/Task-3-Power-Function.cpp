#include <iostream>
#include <windows.h>

using namespace std;

double power(double base, int exponent);

void textattr(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    cout<<"========================Recursion Power========================\n\n";
    double x;
    int y;
    while(true){
        cout<<"Enter base (x): ";
        cin>>x;

        cout<<"Enter exponent (y): ";
        cin>>y;

        cout<<"The Result of ("<<x<<") ^ ("<<y<<") = ";
        textattr(13);
        cout<<power(x, y)<<endl<<endl;
        textattr(15);
    }
    return 0;
}

double power(double base, int exponent) {
    double result = 1;

    if (exponent > 0) {
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
    }
    else if (exponent < 0) {
        for (int i = 0; i < -exponent; i++) {
            result *= base;
        }
        result = 1 / result;
    }

    return result;
}