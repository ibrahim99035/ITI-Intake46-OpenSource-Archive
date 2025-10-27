#include <iostream>
using namespace std;

class Fractions {
    int numerator;
    int denominator;

    int CommonDivisor(int a, int b) {
        a = abs(a);
        b = abs(b);

        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    void simplify() {
        int common_divisor = CommonDivisor(numerator, denominator);

        numerator /= common_divisor;

        denominator /= common_divisor;
    }

public:
    Fractions(int num, int denom) : numerator(num), denominator(denom) {
        simplify();
    }

    Fractions add(Fractions& second){
        int new_numerator = numerator * second.denominator + second.numerator * denominator;
        int new_denominator = denominator * second.denominator;

        return Fractions(new_numerator, new_denominator);
    }

    void display(){
        cout << numerator << "/" << denominator;
    }

    int getNumerator(){
        return numerator;
    }
    int getDenominator(){
        return denominator;
    }

    void setNumerator(int n){
        numerator = n;
    }
    void setDenominator(int d){
        denominator = d;
    }
};

int main() {
    cout << "================================Fractions Calculator================================\n\n";
    int choice;

    do {
        cout << "\n1. Add two fractions\n";
        cout << "2. Display a fraction\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int num1, denom1, num2, denom2;

            cout << "Enter first fraction: ";
            cin >> num1 >> denom1;

            cout << "Enter second fraction: ";
            cin >> num2 >> denom2;

            Fractions frac1(num1, denom1);
            Fractions frac2(num2, denom2);
            Fractions result = frac1.add(frac2);

            cout<<"Result: ";
            frac1.display();

            cout<<" + ";
            frac2.display();

            cout<<" = ";
            result.display();

            cout<<"\n";
        }
        else if (choice == 2) {
            int num, denom;

            cout<<"Enter a fraction: ";
            cin>>num>>denom;

            Fractions frac(num, denom);
            cout<<"Simplified fraction: ";
            frac.display();
            cout<<endl;
        }
        else if (choice == 0) {
            cout<<"Exiting program........\n";
        }
        else {
            cout<<"Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}