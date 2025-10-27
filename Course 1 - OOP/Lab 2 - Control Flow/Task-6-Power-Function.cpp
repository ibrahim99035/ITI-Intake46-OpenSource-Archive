#include <iostream>
using namespace std;

int main()
{
    cout << "=====================X Power Of Y=====================" << endl;

    float x;
    int y;

    cout << "Enter the value of X: ";
    cin >> x;

    cout << "\nEnter the value of Y: ";
    cin >> y;

    float result = 1;

    if (y > 0) {
        for (int i = 0; i < y; i++) {
            result *= x;
        }
    }
    else {
        result = 1;
    }

    cout << "\n"<<x<<"To The Power of "<<y<<"is: "<< result << endl;

    return 0;
}