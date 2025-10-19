#include <iostream>

using namespace std;

int main()
{
    int num;

    cout<<"================Integer To Char================"<<endl;
    cout<<"USE IT FOR 5 TIMES"<<endl;
    for(int i = 0; i < 5; i++){
        cout << "Enter A Number: ";
        cin>>num;

        char holder = num;

        cout<<"The Character Mirror to "<<num<<" is: "<<holder<<endl;
    }
    cout<<"END OF THE ROUND"<<endl;
    return 0;
}
