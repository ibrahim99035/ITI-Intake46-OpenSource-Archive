#include <iostream>
using namespace std;

class Shape {
    int dimension1;
    int dimension2;
public:
    Shape() : Shape(0) {}
    Shape(int d) {
        dimension1 = d;
        dimension2 = d;
    }
    Shape(int d1, int d2) {
        dimension1 = d1;
        dimension2 = d2;
    }

    int getD1(){ return dimension1; }
    int getD2(){ return dimension2; }
    void setD1(int d) { dimension1 = d; }
    void setD2(int d) { dimension2 = d; }
    virtual float area(){
        return 0;
    }//const
};
class Rectangle : public Shape {
public:
    Rectangle(int height, int width) : Shape(height, width) {}
    float area() {
        return getD1() * getD2();
    }
};
class Circle : public Shape {
public:
    Circle(int radius) : Shape(radius) {}
    float area(){
        return 3.14f * getD1() * getD1();
    }
};
class Triangle : public Shape {
public:
    Triangle(int base, int height) : Shape(base, height) {}
    float area(){
        return 0.5f * getD1() * getD2();
    }
};
int main() {
    Rectangle rect(5, 3);
    Circle circle(4);
    Triangle triangle(6, 4);
    cout << "Rectangle area: "<<rect.area() <<endl;
    cout << "Circle area: "<<circle.area() <<endl;
    cout << "Triangle area: "<<triangle.area()<<endl;
    return 0;
}
