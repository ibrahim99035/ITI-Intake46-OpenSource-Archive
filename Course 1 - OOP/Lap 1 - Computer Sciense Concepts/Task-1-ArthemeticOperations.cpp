#include <iostream>

using namespace std;

int x,y;

int addition(int x, int y){
    return x + y;
}

int subtract(int x, int y){
    if(x > y){
        return x - y;
    }else{
        return y - x;
    }
}

int division(int x, int y){
    if(x > y){
        if(y == 0){
            cout<<"ZERO DIVISION ERROR: its impossible to divide any value by zero "<< x << " / " << y <<endl;
        }else{
            return x / y;
        }
    }else{
        if(x == 0){
            cout<<"ZERO DIVISION ERROR: its impossible to divide any value by zero "<< y << " / " << x <<endl;
        }else{
            return y / x;
        }
    }
}

int multiplication(int x, int y){
    return x * y;
}

int modlusRes(int x, int y){
    if(x > y){
        return x % y;
    }else{
        return y % x;
    }
}

int main()
{
    cout<<"================Starting The App================"<<endl;
    cout<<"Enter The First Number: "<<endl;
    cin>>x;
    cout<<"Enter The Second Number: "<<endl;
    cin>>y;

    cout<<"================================================"<<endl;
    cout<<"Addition Result:"<<endl;
    cout<<addition(x,y)<<endl;
    cout<<"================================================"<<endl;
    cout<<"Subtraction Result:"<<endl;
    cout<<subtract(x,y)<<endl;
    cout<<"================================================"<<endl;
    cout<<"Division Result:"<<endl;
    cout<<division(x,y)<<endl;
    cout<<"================================================"<<endl;
    cout<<"Multiplication Result:"<<endl;
    cout<<multiplication(x,y)<<endl;
    cout<<"================================================"<<endl;
    cout<<"Modlus Result:"<<endl;
    cout<<modlusRes(x,y)<<endl;
    cout<<"================================================"<<endl;

    return 0;
}