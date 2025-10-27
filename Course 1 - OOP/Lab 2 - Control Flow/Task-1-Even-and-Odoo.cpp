#include <iostream>

using namespace std;

int main()
{
    int num;
    cout << "Enter  Your Number: ";
    cin>>num;
    cout<<"\n";
    if(num == 0){
        cout<<"Zero is not a valid input"<<endl;
        return 0;
    }
    if(num % 2 == 0){
        cout<<"The Number "<<num<<" Is Even"<<endl;
    }else{
        cout<<"The Number "<<num<<" Is Odd"<<endl;
    }

    return 0;
}