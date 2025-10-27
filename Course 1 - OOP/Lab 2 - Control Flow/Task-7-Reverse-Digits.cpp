#include <iostream>
using namespace std;

int main() {
    cout << "=====================Reverse THE Digits=====================" << endl;
    while(true){
        int num, reversed = 0;
        cout << "Enter your number: ";
        cin >> num;

        while (num != 0) {
            int digit = num % 10;             //getting the last digit
            reversed = reversed * 10 + digit; //put it as a front
            num = num / 10;                   //remove it
        }

        cout << "\n" << "Reversed number: " << reversed << endl;
    }
    return 0;
}