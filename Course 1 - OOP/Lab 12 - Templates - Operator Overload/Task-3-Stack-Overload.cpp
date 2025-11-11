#include <iostream>
using namespace std;
class Stack{
    int* data;
    int stackSize;
    int tos;
public:
    Stack(Stack &StObj){
        cout<<"Copy Constructor CALLED\n";
        stackSize = StObj.stackSize;
        tos = StObj.tos;
        data = new int[stackSize];
        for(int i=0;i<=tos;i++){
            data[i]=StObj.data[i];
        }
    }
    Stack(int _size = 10){
        stackSize = _size;
        data = new int[stackSize];
        tos = -1;
    }
    ~Stack(){
        cout<<"Destroying the object\n";
        delete[] data;
    }
    void push(int value){
        if(tos < stackSize - 1){
            tos++;
            data[tos] = value;
        }else{
            cout<<"STACK OVERFLOW\n";
        }
    }
    int pop(){
        if(tos >= 0){
            int value = data[tos];
            tos--;
            return value;
        }else{
            cout<<"STACK IS EMPTY\n";
            return -1;
        }
    }
    void display(){
        if(tos == -1){
            cout<<"STACK IS EMPTY\n";
            return;
        }
        cout<<"Values: [";
        for(int i = 0; i <= tos; i++){
            cout<<"("<<data[i]<<")";
        }
        cout<<"]\n";
    }

    Stack operator+(Stack& s){
        Stack result(stackSize + s.stackSize);

        for(int i = 0; i <= tos; i++){
            result.push(data[i]);
        }

        for(int i = 0; i <= s.tos; i++){
            result.push(s.data[i]);
        }

        return result;
    }
    Stack& operator=(Stack& s){
        if(this == &s){
            return *this;
        }

        delete[] data;

        stackSize = s.stackSize;
        tos = s.tos;
        data = new int[stackSize];

        for(int i = 0; i <= tos; i++){
            data[i] = s.data[i];
        }
        return *this;
    }
};

int main()
{
    int stackSize;
    cout<<"Enter the size of the main stack: ";
    cin>>stackSize;
    Stack mainS(stackSize);

    cout<<"Enter the size of the secondary stack: ";
    cin>>stackSize;
    Stack secondaryS(stackSize);

    int choice, value, stackChoice;
    do{
        cout<<"\n====Stack Menu====\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Display\n";
        cout<<"4. Merge Stacks (Main + Secondary)\n";
        cout<<"5. Copy Stack (Main = Secondary)\n";
        cout<<"6. Switch Active Stack\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Push to (1-Main, 2-Secondary): ";
                cin>>stackChoice;
                cout<<"Enter value to push: ";
                cin>>value;
                if(stackChoice == 1){
                    mainS.push(value);
                }else if(stackChoice == 2){
                    secondaryS.push(value);
                }else{
                    cout<<"Invalid stack choice!\n";
                }
                break;

            case 2:
                cout<<"Pop from (1-Main, 2-Secondary): ";
                cin>>stackChoice;
                if(stackChoice == 1){
                    value = mainS.pop();
                    if(value != -1){
                        cout<<"Popped value from Main: "<<value<<endl;
                    }
                }else if(stackChoice == 2){
                    value = secondaryS.pop();
                    if(value != -1){
                        cout<<"Popped value from Secondary: "<<value<<endl;
                    }
                }else{
                    cout<<"Invalid stack choice!\n";
                }
                break;

            case 3:
                cout<<"\n--- Main Stack ---\n";
                mainS.display();
                cout<<"\n--- Secondary Stack ---\n";
                secondaryS.display();
                break;

            case 4:
                {
                    cout<<"\nMerging stacks (Main + Secondary)...\n";
                    Stack merged = mainS + secondaryS;
                    cout<<"Merged Stack:\n";
                    merged.display();
                }
                break;

            case 5:
                cout<<"\nCopying Secondary to Main (Main = Secondary)...\n";
                mainS = secondaryS;
                cout<<"Main stack after assignment:\n";
                mainS.display();
                break;

            case 6:
                cout<<"\nSwap functionality not implemented in this version.\n";
                break;

            case 0:
                cout<<"Exiting...\n";
                break;

            default:
                cout<<"Invalid choice!\n";
        }
    }while(choice != 0);

    return 0;
}
