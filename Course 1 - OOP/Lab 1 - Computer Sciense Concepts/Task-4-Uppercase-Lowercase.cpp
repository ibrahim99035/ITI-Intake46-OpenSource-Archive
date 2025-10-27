#include <iostream>

using namespace std;

int main()
{
    char character;

    cout<<"================Lower Case - Upper Case Mixer================"<<endl;
    cout<<"USE IT FOR 5 TIMES"<<endl;
    for(int i = 0; i < 5; i++){
        cout << "Enter A Character: ";
        cin>>character;

        int temp = character;
        if(65 >= temp <= 90){
            int resultInt = temp + 32;
            char resultChar = resultInt;
            cout<<"The Lowercase mirror to your Uppercase "<< character<< " is "<<resultChar<<endl;
        }else if(97 >= temp <= 122){
            int resultInt = temp - 32;
            char resultChar = resultInt;
            cout<<"The Uppercase mirror to your Lowercase "<< character<< " is "<<resultChar<<endl;
        }
    }
    cout<<"END OF THE ROUND"<<endl;
    return 0;
}