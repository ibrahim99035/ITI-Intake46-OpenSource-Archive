#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    cout << "=========== Word & Char Counter ==========="<<endl;
    cout << "Type your sentence and press ENTER to finish: ";

    char c;
    int words = 0, characters = 0;
    bool inWord = false;

    while (true) {
        c = getch();

        if (c == '\r') {
            cout << "\n";
            break;
        }

        cout << c;

        if (c != ' ') {
            characters++;
            if (!inWord) {
                words++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }

    cout <<"\n"<<"Number of words: " << words << endl;
    cout << "Number of characters: " << characters << endl;

    return 0;
}