#include <iostream>
using namespace std;
class Box{
    int boxSize;
    int** boxArr;
public:
    Box(int _size = 10){
        boxSize = _size;
        boxArr = new int*[boxSize];
        for(int i = 0; i < boxSize; i++){
            boxArr[i] = new int[boxSize];
        }
    }
    ~Box(){
        cout<<"Destroying the box\n";
        for(int i = 0; i < boxSize; i++){
            delete[] boxArr[i];
        }
        delete[] boxArr;
    }
    void setArr(int val, int i,int j){
        boxArr[i][j] = val;
    }
    int getArr(int row, int col){
        return boxArr[row][col];
    }
};
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
        Box boxObj(boxSize);
        for (int i = 0; i < boxSize; i++) {
            for (int j = 0; j < boxSize; j++) {
                boxObj.setArr(0, i, j);
            }
        }
        int row = 0;
        int col = boxSize / 2;
        boxObj.setArr(1, row, col);
        for (int num = 2; num <= boxSize * boxSize; num++) {
            int nextRow = (row - 1 + boxSize) % boxSize;
            int nextCol = (col + 1) % boxSize;
            if (boxObj.getArr(nextRow, nextCol)) {
                row = (row + 1) % boxSize;
            } else {
                row = nextRow;
                col = nextCol;
            }
            boxObj.setArr(num, row, col);
        }
        cout << "\nMagic Box of size " << boxSize << ":\n\n";
        for (int i = 0; i < boxSize; i++) {
            for (int j = 0; j < boxSize; j++) {
                cout << "[" << boxObj.getArr(i, j) << "]\t";
            }
            cout << "\n";
        }
        cout << "\n===========================================================\n\n";
    }
    return 0;
}