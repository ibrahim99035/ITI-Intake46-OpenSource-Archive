#include <iostream>
#include <iomanip>
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
        if(denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        int common_divisor = CommonDivisor(numerator, denominator);
        numerator /= common_divisor;
        denominator /= common_divisor;
    }

public:
    Fractions(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if(denominator == 0) {
            cout << "Error: Denominator cannot be zero. Setting to 1.\n";
            denominator = 1;
        }
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
        simplify();
    }

    void setDenominator(int d){
        if(d == 0) {
            cout << "Error: Denominator cannot be zero.\n";
            return;
        }
        denominator = d;
        simplify();
    }

    Fractions operator+(Fractions f){
        Fractions result = add(f);
        return result;
    }

    Fractions operator+(int num){
        Fractions result(numerator + num * denominator, denominator);
        return result;
    }

    friend Fractions operator+(int num, Fractions f);

    int operator==(Fractions f){
        return numerator == f.numerator && denominator == f.denominator;
    }

    int operator!=(Fractions f){
        return !(*this == f);
    }

    Fractions& operator++(){
        numerator += denominator;
        return *this;
    }

    Fractions operator++(int){
        Fractions result(numerator, denominator);
        numerator += denominator;
        return result;
    }
};

Fractions operator+(int num, Fractions f){
    Fractions result(f.numerator + num * f.denominator, f.denominator);
    return result;
}

int main() {

    int choice;

    do {
        cout << "\n------------------------------------- MENU -------------------------------------\n";
        cout << "  1 Add Two Fractions (f1 + f2)\n";
        cout << "  2 Add Fraction and Integer (f + n)\n";
        cout << "  3 Add Integer and Fraction (n + f)\n";
        cout << "  4 Compare Two Fractions (==, !=)\n";
        cout << "  5 Increment Fraction (++f, f++)\n";
        cout << "  6 Display Simplified Fraction\n";
        cout << "  0 Exit Program\n";
        cout << "--------------------------------------------------------------------------------\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << "\n";

        if (choice == 1) {
            int num1, denom1, num2, denom2;
            cout << "Enter first fraction (numerator denominator): ";
            cin >> num1 >> denom1;
            cout << "Enter second fraction (numerator denominator): ";
            cin >> num2 >> denom2;

            Fractions frac1(num1, denom1);
            Fractions frac2(num2, denom2);
            Fractions result = frac1 + frac2;

            cout << "\nResult: ";
            frac1.display();
            cout << " + ";
            frac2.display();
            cout << " = ";
            result.display();
            cout << "\n";
        }
        else if (choice == 2) {
            int num, denom, integer;
            cout << "Enter fraction (numerator denominator): ";
            cin >> num >> denom;
            cout << "Enter integer: ";
            cin >> integer;

            Fractions frac(num, denom);
            Fractions result = frac + integer;

            cout << "\nResult: ";
            frac.display();
            cout << " + " << integer << " = ";
            result.display();
            cout << "\n";
        }
        else if (choice == 3) {
            int num, denom, integer;
            cout << "Enter integer: ";
            cin >> integer;
            cout << "Enter fraction (numerator denominator): ";
            cin >> num >> denom;

            Fractions frac(num, denom);
            Fractions result = integer + frac;

            cout << "\nResult: " << integer << " + ";
            frac.display();
            cout << " = ";
            result.display();
            cout << "\n";
        }
        else if (choice == 4) {
            int num1, denom1, num2, denom2;
            cout << "Enter first fraction (numerator denominator): ";
            cin >> num1 >> denom1;
            cout << "Enter second fraction (numerator denominator): ";
            cin >> num2 >> denom2;

            Fractions frac1(num1, denom1);
            Fractions frac2(num2, denom2);

            cout << "\nComparison Results:\n";
            frac1.display();
            cout << (frac1 == frac2 ? " == " : " != ");
            frac2.display();
            cout << " is " << (frac1 == frac2 ? "TRUE" : "FALSE") << "\n";
        }
        else if (choice == 5) {
            int num, denom;
            cout << "Enter fraction (numerator denominator): ";
            cin >> num >> denom;

            Fractions frac(num, denom);
            cout << "\nOriginal fraction: ";
            frac.display();

            Fractions postfix = frac++;
            cout << "\nAfter postfix increment (f++):";
            cout << "\n  Returned value: ";
            postfix.display();
            cout << "\n  Current value: ";
            frac.display();

            Fractions frac2(num, denom);
            ++frac2;
            cout << "\n\nAfter prefix increment (++f):";
            cout << "\n  Current value: ";
            frac2.display();
            cout << "\n";
        }
        else if (choice == 6) {
            int num, denom;
            cout << "Enter fraction (numerator denominator): ";
            cin >> num >> denom;

            Fractions frac(num, denom);
            cout << "\nSimplified fraction: ";
            frac.display();
            cout << "\n";
        }
        else if (choice == 0) {
            cout<<"Exiting\n\n";
        }
        else {
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
