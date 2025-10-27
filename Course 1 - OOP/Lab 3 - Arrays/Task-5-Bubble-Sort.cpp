#include <iostream>
using namespace std;

int main() {
    int size;
    cout<<"=======================Bubble Sort Algorithm=======================\n\n";

    cout << "Enter the size of your array: ";
    cin >> size;

    int arr[size];

    cout << "Enter your " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element N." << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nYour Array Unsorted:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "\nYour Array Sorted: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}