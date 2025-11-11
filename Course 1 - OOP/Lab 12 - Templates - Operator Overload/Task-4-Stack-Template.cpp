#include <iostream>
using namespace std;

template<class t>

class Stack{
    t* data;
    int stackSize;
    int tos;

public:
    Stack(int _size = 10){
        stackSize = _size;
        data = new t[stackSize];
        tos = -1;
    }

    ~Stack(){
        cout<<"Destroying the object\n";
        delete[] data;
    }

    void push(t value){
        if(tos < stackSize - 1){
            tos++;
            data[tos] = value;
            cout<<value<<" Pushed\n";
        }else{
            cout<<"STACK OVERFLOW\n";
        }
    }

    t pop(){
        if(tos >= 0){
            t value = data[tos];
            tos--;
            cout<<value<<" Poped\n";
            return value;
        }else{
            cout<<"STACK IS EMPTY\n";
            return -1;
        }
    }
};

int main(){
    Stack<int> s1(4);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();


    Stack<float> s2(4);
    s2.push(1.8);
    s2.push(2.6);
    s2.push(3.4);
    s2.push(4.4);
    s2.pop();
    s2.pop();
    s2.pop();
    s2.pop();

    return 0;
}
