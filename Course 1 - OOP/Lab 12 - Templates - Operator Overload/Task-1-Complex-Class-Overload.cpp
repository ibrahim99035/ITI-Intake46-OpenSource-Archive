/*
Tasks:
    imaginary number like the lecture
    1- setters and getters for real and imaginary
    2- member print + standalone print
    3- member add
    4- standalone  subtract
*/

#include <iostream>
using namespace std;

class Complex{
    float real;
    float img;

public:

    Complex(){
        real = 0;
        img = 0;
    }

    Complex(float _real, float _img){
        real  = _real;
        img = _img;
    }

    Complex(Complex& obj){
        real  = obj.real;
        img  = obj.img;
    }

    float getReal(){
        return real;
    }

    float getImg(){
        return img;
    }

    void setReal(float r){
        real = r;
    }

    void setImg(float i){
        img = i;
    }


    void print(){
        if(img >= 0){
            cout<<real<<" + "<<img<<"i\n";
        }else{
            cout<<real<<" - "<<-img<<"i\n";
        }
    }

    Complex add(Complex c){
        Complex result;

        result.real = real + c.real;
        result.img = img + c.img;

        return result;
    }

    Complex operator+(Complex c){
        Complex result;

        result.real = real + c.real;
        result.img = img + c.img;

        return result;
    }

    Complex operator+(int c){
        Complex result(real+c, img);

        return result;
    }
    friend Complex operator+(int c,Complex z);

    int operator==(Complex c){
        return real==c.real&&img==c.img;
    }

    int operator!=(Complex c){
        return !(*this == c);
    }

    Complex operator=(Complex c){
        real = c.real;
        img = c.img;
        return *this;
    }

    Complex operator++(){
        real++;

        return *this;
    }

    Complex operator++(int){
        Complex result(real, img);
        real++;

        return result;
    }

    explicit operator int(){
        return real;
    }
};

void print(Complex c);

Complex operator+(int c,Complex z){
    Complex result(z.real+c, z.img);

    return result;
}

Complex subtract(Complex c1, Complex c2);

int main(){
    cout<<"===============Imaginary Numbers & Operators Overload===============\n\n";

    Complex num1, num2, result;

    int num1Real, num1Img, num2Real, num2Img;

    cout<<"Num 1 Real Value: ";
    cin>>num1Real;

    cout<<"Num 1 Imaginary Value: ";
    cin>>num1Img;

    cout<<"Num 2 Real Value: ";
    cin>>num2Real;

    cout<<"Num 2 Imaginary Value: ";
    cin>>num2Img;

    cout<<"Processing..........\n\n";

    num1.setReal(num1Real);
    num1.setImg(num1Img);

    num2.setReal(num2Real);
    num2.setImg(num2Img);

    cout<<"(MEMBER PRINTING) - Number 1: ";
    num1.print();

    cout<<"(Standalone PRINTING) - Number 2: ";
    print(num2);

    result = num1.add(num2);
    cout<<"Member Addition: ";
    result.print();

    result = subtract(num1, num2);
    cout<<"Standalone Subtraction: ";
    print(result);

    cout<<"Is Num1==Num2?\n";
    if(num1==num2){
        cout<<"Equal\n\n";
    }else if(num1!=num2){
        cout<<"Not Equal\n\n";
    }

    cout<<"+ Operator Overload Result:\n";
    result = num1 + num2;
    print(result);

    cout<<"Operator Overload Complex + i:\n";
    result = num1 + 9;
    print(result);

    cout<<"Operator Overload i + Complex:\n";
    result = 12 + num2;
    print(result);

    cout<<"Num 1 Casting\n";
    int i = (int)num1;
    cout<<i;

    return 0;
}

void print(Complex c){
    if(c.getImg() >= 0){
        cout<<c.getReal()<<" + "<<c.getImg()<<"i\n\n";
    }else{
        cout<<c.getReal()<<" - "<<-c.getImg()<<"i\n\n";
    }
}

Complex subtract(Complex c1, Complex c2){
    Complex result;
    result.setReal(c1.getReal() - c2.getReal());
    result.setImg(c1.getImg() - c2.getImg());
    return result;
}
