#include <iostream>

using namespace std;

int main()
{
    cout << "===========Factorial Program===========" << endl;
    int num;
    int factorial = 1;
    while(true){
        cout<<"Enter Your Number: ";
        cin>>num;
        cout<<"\n";

        for(int i=1; i<=num; i++){
            factorial *=i;
        }

        cout<<"The Factorial to "<<num<<" is "<<factorial<<endl;
        factorial = 1;
    }
    return 0;
}