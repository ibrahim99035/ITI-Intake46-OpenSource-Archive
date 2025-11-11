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
    }
    virtual ~Shape() {}

    virtual void print() {
        cout << "Shape with area: " << area() << endl;
    }
};

class Rectangle : public Shape {
public:
    Rectangle(int height, int width) : Shape(height, width) {}
    virtual float area() {
        return getD1() * getD2();
    }
    void print() {
        cout << "Rectangle (height=" << getD1() << ", width=" << getD2() << ") area: " << area() << endl;
    }
};

class Square : public Rectangle {
public:
    Square(int side) : Rectangle(side, side) {}
    float area() {
        return getD1() * getD1();
    }
    void print() {
        cout << "Square (side=" << getD1() << ") area: " << area() << endl;
    }
};

class Circle : public Shape {
public:
    Circle(int radius) : Shape(radius) {}
    float area() {
        return 3.14 * getD1() * getD1();
    }
    void print() {
        cout << "Circle (radius=" << getD1() << ") area: " << area() << endl;
    }
};

class Triangle : public Shape {
public:
    Triangle(int base, int height) : Shape(base, height) {}
    float area() {
        return 0.5 * getD1() * getD2();
    }
    void print() {
        cout << "Triangle (base=" << getD1() << ", height=" << getD2() << ") area: " << area() << endl;
    }
};

void printShape(Shape* shape) {
    shape->print();
}

int main() {
    int rectHeight, rectWidth, circleRadius, triBase, triHeight, squareSide;

    cout << "Enter rectangle height and width: ";
    cin >> rectHeight >> rectWidth;

    cout << "Enter circle radius: ";
    cin >> circleRadius;

    cout << "Enter triangle base and height: ";
    cin >> triBase >> triHeight;

    cout << "Enter square side: ";
    cin >> squareSide;

    cout << "\n";

    Shape* shapes[4];
    shapes[0] = new Rectangle(rectHeight, rectWidth);
    shapes[1] = new Circle(circleRadius);
    shapes[2] = new Triangle(triBase, triHeight);
    shapes[3] = new Square(squareSide);

    cout << "Rectangle area: " << shapes[0]->area() << endl;
    cout << "Circle area: " << shapes[1]->area() << endl;
    cout << "Triangle area: " << shapes[2]->area() << endl;
    cout << "Square area: " << shapes[3]->area() << endl;

    cout << "\nUsing printShape function:\n";
    for(int i = 0; i < 4; i++) {
        printShape(shapes[i]);
    }

    for(int i = 0; i < 4; i++) {
        delete shapes[i];
    }

    return 0;
}
