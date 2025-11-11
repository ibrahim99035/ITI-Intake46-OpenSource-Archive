#include <iostream>

using namespace std;
class Math{
    Math(){}
public:
    static int addition(int x, int y){
        return x + y;
    }

    static int subtract(int x, int y){
        if(x > y){
            return x - y;
        }else{
            return y - x;
        }
    }

    static int division(int x, int y){
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

    static int multiplication(int x, int y){
        return x * y;
    }

    static int modlusRes(int x, int y){
        if(x > y){
            return x % y;
        }else{
            return y % x;
        }
    }
};

int main()
{
    cout<<"================Starting The App================"<<endl;
    int x,y;
    cout<<"Enter The First Number: "<<endl;
    cin>>x;
    cout<<"Enter The Second Number: "<<endl;
    cin>>y;

    cout<<"================================================"<<endl;
    cout<<"Addition Result:"<<endl;
    cout<<Math::addition(x,y)<<endl;
    cout<<"================================================"<<endl;
    cout<<"Subtraction Result:"<<endl;
    cout<<Math::subtract(x,y)<<endl;
    cout<<"================================================"<<endl;
    cout<<"Division Result:"<<endl;
    cout<<Math::division(x,y)<<endl;
    cout<<"================================================"<<endl;
    cout<<"Multiplication Result:"<<endl;
    cout<<Math::multiplication(x,y)<<endl;
    cout<<"================================================"<<endl;
    cout<<"Modlus Result:"<<endl;
    cout<<Math::modlusRes(x,y)<<endl;
    cout<<"================================================"<<endl;

    return 0;
}
