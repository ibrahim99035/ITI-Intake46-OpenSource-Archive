#include <iostream>

using namespace std;

void swapByAddress(int* ptr1, int* ptr2);

int main()
{
    cout << "==========================Swap By Address==========================\n\n" << endl;
    while(true){
        int var1, var2;
        cout<<"Enter First Number: ";
        cin>>var1;
        cout<<"Enter Second Number: ";
        cin>>var2;

        int* ptr1 = &var1;
        int* ptr2 = &var2;

        cout<<"Data: ("<<var1<<", "<<var2<<").\n";
        cout<<"Refs: ("<<ptr1<<", "<<ptr2<<").\n";

        swapByAddress(ptr1, ptr2);

        cout<<"\n--------------SWAPED--------------\n\n";

        cout<<"Data: ("<<var1<<", "<<var2<<").\n";
        cout<<"Refs: ("<<ptr1<<", "<<ptr2<<").\n";
    }
    return 0;
}

void swapByAddress(int* ptr1, int* ptr2){
    int temp;
    temp = *ptr1;
    *ptr1 =  *ptr2;
    *ptr2 =  temp;
}
