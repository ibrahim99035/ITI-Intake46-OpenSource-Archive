#include <iostream>
using namespace std;

class Complex{
    float real;
    float img;
    static int counter;
public:
    static int getCounter(){
        return counter;
    }

    Complex(){
        real = 0;
        img = 0;
        counter++;
    }

    Complex(float _real, float _img){
        real  = _real;
        img = _img;
        counter++;
    }

    Complex(Complex& obj){
        real  = obj.real;
        img  = obj.img;
        counter++;
    }

    ~Complex(){
        counter--;
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
    friend void Fprint(Complex c);
};

int Complex::counter = 0;

void print(Complex c);
Complex subtract(Complex c1, Complex c2);

void Fprint(Complex c){
    cout<<"real: "<<real<<"\nimaginary: "<<img<<endl;
}

int main(){
    cout<<"=======================Imaginary Numbers=======================\n";

    Complex num1, num2, result;
    float num1Real, num1Img, num2Real, num2Img;

    cout<<"Num 1 Real Value: ";
    cin>>num1Real;
    cout<<"Num 1 Imaginary Value: ";
    cin>>num1Img;
    cout<<"Num 2 Real Value: ";
    cin>>num2Real;
    cout<<"Num 2 Imaginary Value: ";
    cin>>num2Img;

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

    cout<<"Main Function - Object Counter: "<<Complex::getCounter()<<"\n";

    return 0;
}

void print(Complex c){
    if(c.getImg() >= 0){
        cout<<c.getReal()<<" + "<<c.getImg()<<"i\n";
    }else{
        cout<<c.getReal()<<" - "<<-c.getImg()<<"i\n";
    }
}

Complex subtract(Complex c1, Complex c2){
    Complex result;
    result.setReal(c1.getReal() - c2.getReal());
    result.setImg(c1.getImg() - c2.getImg());
    return result;
}
