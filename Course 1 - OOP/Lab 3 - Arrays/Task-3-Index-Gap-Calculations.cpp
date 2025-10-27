#include <iostream>

using namespace std;

int main()
{
    cout << "==========================Biggest Gap between 2 Values==========================\n\n";

    int length, Val, ind1, ind2;
    int maxGap = 0;

    cout<<"\nWhat is The Size of Your Array?? ";

    cin>>length;

    int arr[length];

    cout<<"\n--------------------Start Entering Your Values--------------------"<<"\n\n";

    for(int i = 0; i < length; i++){
        cout<<"Value No."<<i + 1<<": ";
        cin>>arr[i];
        cout<<"\n";
    }

    cout<<"Your Array: [";
    for(int i = 0; i < length; i++){
        if(i == length - 1){
            cout<<arr[i];
        }else{
            cout<<arr[i]<<", ";
        }

    }
    cout<<"]"<<"\n\n";

    for(int i = 0; i < length; i++){
        for(int j = length - 1; j > i; j--){
            if(arr[i] == arr[j]){
                int gap = j - i;
                if(gap > maxGap){
                    maxGap = gap;
                    Val = arr[i];
                    ind1 = i + 1;
                    ind2 = j + 1;
                }
                break;

            }
        }
    }

    cout<<"The Max Gap Between 2 identical elements is: ["<<maxGap<<"] For the value ["<<Val<<"] between the index ("<<ind1<<") and ("<<ind2<<")\n\n";

    return 0;
}
