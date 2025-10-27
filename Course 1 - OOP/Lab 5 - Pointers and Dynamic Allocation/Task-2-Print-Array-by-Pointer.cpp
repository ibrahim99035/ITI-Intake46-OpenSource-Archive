#include <iostream>

using namespace std;

int main()
{
    cout<<"=========================Array Printer=========================\n\n";

    int arrsize;
    cout<<"What is the size of your array? ";
    cin>>arrsize;

    int arr[arrsize];
    for(int i = 0; i < arrsize; i++){
        cout<<"\n\nItem Number ("<<i+1<<"): ";
        cin>>arr[i];
    }

    cout<<"\n\n-------------Normal Print-------------\n\n";
    for(int i = 0; i < arrsize; i++){
        if(i == arrsize - 1){cout<<"["<<arr[i]<<"]";}else{cout<<"["<<arr[i]<<"], ";}
    }

    int* ptr = arr;

    cout<<"\n\n-------------Pointer Print [Method 1]-------------\n\n";
    cout<<"[";
    for(int i = 0; i < arrsize; i++){
        if(i == arrsize - 1){cout<<"("<<ptr[i]<<")";}else{cout<<"("<<ptr[i]<<"), ";}
    }
    cout<<"]";

    cout<<"\n\n-------------Pointer Print [Method 2]-------------\n\n";
    cout<<"[";
    for(int i = 0; i < arrsize; i++){
        if(i == arrsize - 1){cout<<"("<<*(ptr + i)<<")";}else{cout<<"("<<*(ptr + i)<<"), ";}
    }
    cout<<"[";

    cout<<"\n\n-------------Pointer Print [Method 3]-------------\n\n";
    cout<<"[";
    for(int i = 0; i < arrsize; i++){
        if(i == arrsize - 1){cout<<"("<<*(arr + i)<<")";}else{cout<<"("<<*(arr + i)<<"), ";}
    }
    cout<<"]";

    return 0;
}
