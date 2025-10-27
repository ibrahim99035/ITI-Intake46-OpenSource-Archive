#include <iostream>

using namespace std;

int main()
{
    cout << "===========================1D array operations===========================" << endl;

    int length, maximum, minimum;
    int sum = 0;
    cout<<"\nWhat is The Size of Your Array?? ";
    cin>>length;

    int arr[length];

    cout<<"\n--------------------Start Entering Your Values--------------------"<<"\n\n";

    for(int i = 0; i < length; i++){
        cout<<"Value No."<<i + 1<<": ";
        cin>>arr[i];
        cout<<"\n";
    }

    maximum = arr[0];
    minimum = arr[0];

    cout<<"Your Array: [";
    for(int i = 0; i < length; i++){
        if(i == length - 1){
            cout<<arr[i];
        }else{
            cout<<arr[i]<<", ";
        }

        sum += arr[i];

        if(maximum < arr[i]){
            maximum =arr[i];
        }

        if(minimum > arr[i]){
            minimum =arr[i];
        }
    }
    float average = sum/length;
    cout<<"]"<<"\n\n";

    cout<<"The Sum Of Elements: "<<sum<<"\n\n";
    cout<<"The Max Element: "<<maximum<<"\n\n";
    cout<<"The Min Element: "<<minimum<<"\n\n";
    cout<<"The Average value: "<<average<<"\n\n";

    cout<<"You May Search for a value: ";
    int searchVal;
    int searchRes = -1;
    cin>>searchVal;
    for(int i = 0; i < length; i++){
        if(searchVal == arr[i]){
                searchRes = i;
        }
    }
    cout<<"Result: "<<searchRes<<"Index"<<"\n\n\n";

    cout<<"====================================END OF SESSION====================================";
    return 0;
}