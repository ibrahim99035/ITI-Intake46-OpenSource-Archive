#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    int inputPoint;
    for(int i = 0; i < 5; i++){
        cout<<"Enter the number no."<<i+1<<": ";
        cin>>inputPoint;
        cout<<"\n";
        sum += inputPoint;
    }
    cout<<"The Sum of your 5 numbers is: "<<sum;
    cout<<"\n";

    return 0;
}