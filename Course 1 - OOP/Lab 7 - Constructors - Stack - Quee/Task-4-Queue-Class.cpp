#include <iostream>
using namespace std;

class Quee{
    int* data;
    int queeSize;
    int start;
    int Qend;
    int counter;

public:
    Quee(int _size = 10){
        queeSize = _size;
        data = new int[queeSize];
        start = 0;
        Qend = -1;
        counter = 0;
    }

    ~Quee(){
        cout<<"Destroying the quee object\n";
        delete[] data;
    }

    void enquee(int value){
        if(counter < queeSize){
            Qend = (Qend + 1) % queeSize;
            data[Qend] = value;
            counter++;
            cout<<"Enqueued: "<<value<<endl;
        }else{
            cout<<"Quee is Full\n";
        }
    }

    int dequee(){
        if(counter > 0){
            int value = data[start];
            start = (start + 1) % queeSize;
            counter--;
            return value;
        }else{
            cout<<"Quee is empty\n";
            return -1;
        }
    }

    void display(){
        if(counter==0){
            cout<<"Quee is empty\n";
            return;
        }
        cout<<"Quee values: [";
        for(int i = 0; i < counter; i++){
            cout<<"("<<data[(start + i) % queeSize]<<")";
        }
        cout<<"]\n";
    }
};

int main()
{
    int inputSize;
    cout<<"Enter the size of the quee: ";
    cin>>inputSize;

    Quee q(inputSize);

    int choice, value;

    do{
        cout<<"\n=====Quee Menu=====\n";
        cout<<"1. Enquee\n";
        cout<<"2. Dequee\n";
        cout<<"3. Display\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value: ";
                cin>>value;
                q.enquee(value);
                break;
            case 2:
                value = q.dequee();
                if(value != -1){
                    cout<<"Dequeed value: "<<value<<endl;
                }
                break;
            case 3:
                q.display();
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
