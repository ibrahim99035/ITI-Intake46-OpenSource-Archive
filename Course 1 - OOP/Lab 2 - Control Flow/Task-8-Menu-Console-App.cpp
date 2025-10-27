#include <iostream>
#include <conio.h>   // for getch()
#include <cstdlib>   // for system()
using namespace std;

int main() {
    char choice;

    while (true) {
        system("cls"); // clear screen
        cout << "===================Menu Display====================\n";
        cout << "[M] - Back to Menu\n";
        cout << "[D] - Display Data\n";
        cout << "[E] - Exit Program\n";
        cout << "===================================================\n";
        cout << "Enter your choice: ";

        choice = getch(); // wait for user key

        if (choice == 'e' || choice == 'E') {
            system("cls");
            cout << "Exiting program... Goodbye!\n";
            break;
        }
        else if (choice == 'm' || choice == 'M') {
            // show menu until user exits
            while (true) {
                system("cls");
                cout << "===================Menu Display====================\n";
                cout << "[M] - Back to Menu\n";
                cout << "[D] - Display Data\n";
                cout << "[E] - Exit Program\n";
                cout << "===================================================\n";
                cout << "Enter your choice: ";

                char menuChoice = getch();
                system("cls");

                if (menuChoice == 'd' || menuChoice == 'D') {
                    cout << "HI :)\n";
                    while (true) {
                        char back = getch();
                        if (back == 'm' || back == 'M') break;
                    }
                }
                else if (menuChoice == 'm' || menuChoice == 'M') {
                    continue;
                }
                else if (menuChoice == 'e' || menuChoice == 'E') {
                    system("cls");
                    cout << "Exiting program... Goodbye!\n";
                    return 0;
                }
                else {
                    cout << "Invalid input!\n";
                    return 0;
                }
            }
        }
        else {
            system("cls");
            cout << "Invalid input";
            return 0;
        }
    }

    return 0;
}