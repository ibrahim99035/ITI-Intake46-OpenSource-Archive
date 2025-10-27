#include <iostream>

using namespace std;

int main(){
    cout << "=====================2D Array Operations=====================\n\n";

    int rows, columns, rowSum;
    cout<<"Number of Elements in Each Array [Rows]: ";
    cin>>rows;
    cout<<"Number of Arrays [Columns]: ";
    cin>>columns;
    int arr[rows][columns];

    cout<<"\\n\\n------------------------DATA ENTRY BEGIN------------------------\n\n";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout<<"Value of cell ("<<i<<", "<<j<<"): ";
            cin>>arr[i][j];
        }
    }
    cout<<"-------------------------DATA ENTRY DONE-------------------------\n\n";

    for(int i = 0; i < columns; i++){
        rowSum = 0;
        for(int j = 0; j < rows; j++){
            rowSum += arr[j][i];
            cout<<"["<<arr[j][i]<<"] ";
        }
        cout<<"Sum = ("<<rowSum<<") ";
        cout<<"Average = ("<<(float)rowSum/columns<<")\n";
    }

    return 0;
}