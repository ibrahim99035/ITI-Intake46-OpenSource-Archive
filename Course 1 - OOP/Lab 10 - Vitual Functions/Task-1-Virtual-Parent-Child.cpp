#include <iostream>
using namespace std;

class Parent {
    int x;
    int y;
public:
    Parent(int x, int y) : x(x), y(y) {}
    virtual int add() {
        return x + y;
    }
    virtual void display(){
        cout<<"Parent: x="<<x<<", y="<<y<<endl;
    }
    virtual ~Parent(){}
};

class Child : public Parent{
    int z;
public:
    Child(int x, int y, int _z) : Parent(x, y){
        z = _z;
    }
    int add() {
        return Parent::add() + z;
    }
    void display() {
        Parent::display();
        cout<<"Child: z="<<z<<endl;
    }
};

int main() {
    double px, py, cx, cy, cz;
    cout<<"Enter Parent x: ";
    cin>>px;
    cout<<"Enter Parent y: ";
    cin>>py;
    cout<<"Enter Child x: ";
    cin>>cx;
    cout<<"Enter Child y: ";
    cin>>cy;
    cout<<"Enter Child z: ";
    cin>>cz;

    Parent parent(px, py);
    Child child(cx, cy, cz);

    cout<<"\nParent add(): "<<parent.add()<<endl;
    cout<<"Child add(): "<<child.add()<<endl;

    return 0;
}
