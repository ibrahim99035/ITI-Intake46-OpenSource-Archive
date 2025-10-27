#include <iostream>
using namespace std;

int main() {
    cout << "=========== Fibonacci Numbers ===========\n";

    while (true) {
        int n;
        cout << "Enter the index (or -1 to exit): ";
        cin >> n;

        if (n == -1) {
            cout << "Exiting program... Goodbye!\n";
            break;
        }

        int a = 0, b = 1, next;

        if (n == 0) {
            cout << "Fibonacci(0) = 0" << endl << endl;
            continue;
        }
        else if (n == 1) {
            cout << "Fibonacci(1) = 1" << endl << endl;
            continue;
        }

        // Calculate Fibonacci number
        for (int i = 2; i <= n; i++) {
            next = a + b;
            a = b;
            b = next;
        }

        cout << "Fibonacci(" << n << ") = " << b << endl;

        // Print full series
        cout << "\nFull series up to index " << n << ":\n";
        a = 0; b = 1;
        cout << a << " " << b << " ";
        for (int i = 2; i <= n; i++) {
            next = a + b;
            cout << next << " ";
            a = b;
            b = next;
        }
        cout << "\n\n";
    }

    return 0;
}