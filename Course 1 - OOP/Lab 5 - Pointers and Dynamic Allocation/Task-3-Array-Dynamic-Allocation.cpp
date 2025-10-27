#include <iostream>

using namespace std;

int main()
{
    cout << "==========================Array Dynamic Allocation==========================\n\n";

    int arrsize;
    cout<<"Numbers of addresses you want to allocate: ";
    cin>>arrsize;

    int* ptr = new int[arrsize];
    for(int i = 0; i < arrsize; i++){
        cout<<"\nItem Number ("<<i+1<<"): ";
        cin>>ptr[i];
    }

    cout<<"[";
    for(int i = 0; i < arrsize; i++){
        if(i == arrsize - 1){cout<<"("<<ptr[i]<<")";}else{cout<<"("<<ptr[i]<<"), ";}
    }
    cout<<"]";

    delete[] ptr;

    return 0;
}