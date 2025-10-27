#include <iostream>
#include <windows.h>

using namespace std;

int reverseInteger(int n);

void textattr(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    cout<<"=========================Integer Mirror=========================\n\n";

    int number;
    while(true){
        cout<<"Enter an integer - 0 to Exit: ";
        cin>>number;

        if(number == 0){break;}

        int reversed = reverseInteger(number);

        cout<<number<<" Reversed is ";
        textattr(10);
        cout<<reversed<<endl;
        textattr(15);
    }
    textattr(12);
    cout<<"=========================Program Ending=========================\n\n";
    textattr(15);
    return 0;
}

int reverseInteger(int n) {
    int reversed = 0;

    while (n != 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n = n / 10;
    }

    return reversed;
}