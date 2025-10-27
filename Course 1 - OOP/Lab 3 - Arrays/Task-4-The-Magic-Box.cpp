#include <iostream>
using namespace std;

int main() {
    cout << "==================== Dynamic Magic Box ====================\n\n";

    while (true) {
        int boxSize;
        cout << "What is your Box Size? ";
        cin >> boxSize;

        if (boxSize == 0) {
            cout << "\nProgram terminated.\n";
            break;
        }

        while (boxSize % 2 == 0 || boxSize == 1) {
            cout << "\nONLY ODD NUMBERS EXCEPT (1)\n";
            cout << "Try Again: ";
            cin >> boxSize;
        }

        int arr[boxSize][boxSize];


        for (int i = 0; i < boxSize; i++) {
            for (int j = 0; j < boxSize; j++) {
                arr[i][j] = 0;
            }
        }

        int row = 0;
        int col = boxSize / 2;
        arr[row][col] = 1;

        for (int num = 2; num <= boxSize * boxSize; num++) {
            int nextRow = (row - 1 + boxSize) % boxSize;
            int nextCol = (col + 1) % boxSize;

            if (arr[nextRow][nextCol] != 0) {
                row = (row + 1) % boxSize;
            } else {
                row = nextRow;
                col = nextCol;
            }

            arr[row][col] = num;
        }

        cout << "\nMagic Box of size " << boxSize << ":\n\n";
        for (int i = 0; i < boxSize; i++) {
            for (int j = 0; j < boxSize; j++) {
                cout << "[" << arr[i][j] << "]\t";
            }
            cout << "\n";
        }

        cout << "\n===========================================================\n\n";
    }

    return 0;
}