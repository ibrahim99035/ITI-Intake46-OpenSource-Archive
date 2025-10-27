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
};

int main()
{
    int stackSize;
    cout<<"Enter the size of the stack: ";
    cin>>stackSize;
    Stack s(stackSize);
    Stack mainS(s);

    int choice, value;
    do{
        cout<<"\n====Stack Menu====\n";
        cout<<"1. Push\n2. Pop\n3. Display\n0. Exit\nEnter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value to push: ";
                cin>>value;
                mainS.push(value);
                break;
            case 2:
                value = mainS.pop();
                if(value != -1){
                    cout<<"Popped value: "<<value<<endl;
                }
                break;
            case 3:
                mainS.display();
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