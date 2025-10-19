#include <iostream>

using namespace std;

int main()
{
    char character;

    cout<<"================Char To Integer================"<<endl;
    cout<<"USE IT FOR 5 TIMES"<<endl;
    for(int i = 0; i < 5; i++){
        cout << "Enter A Character: ";
        cin>>character;
        if('Z' <=character >= 'A' || 'z' <=character >= 'a'){

            int holder = character;

            cout<<"The Integer Mirror to "<<character<<" is: "<<holder<<endl;
        } else{
            cout<<"Only Characters Allows NO NUMBERS"<<endl;
        }
    }
    cout<<"END OF THE ROUND"<<endl;
    return 0;
}
