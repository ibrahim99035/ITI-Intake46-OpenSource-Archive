#include <iostream>
using namespace std;

class Point{
    int x, y;
public:
    Point(int _x = 0, int _y = 0){
        x = _x;
        y = _y;
    }

    ~Point(){
        cout<<"Point ("<<x<<", "<<y<<") Destroyed\n";
    }

    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
};

class Rectangle{
    Point upperLeft;
    Point lowerRight;
public:
    Rectangle(int x1, int y1, int x2, int y2): upperLeft(x1, y1), lowerRight(x2, y2) {}

    ~Rectangle(){
        cout<<"Rectangle Destroyed\n";
    }
};

class Circle{
    Point center;
    int reduis;
public:
    Circle(int x,int y): center(x, y) {}

    ~Circle(){
        cout<<"Circle Destroyed\n";
    }
};

class Tringle{
    Point topCorner;
    Point rightCorner;
    Point leftCorner;
public:
    Tringle(int x1, int y1, int x2, int y2, int x3, int y3): topCorner(x1, y1), rightCorner(x2, y2), leftCorner(x3, y3) {}
    ~Tringle(){
        cout<<"Tringle Destroyed\n";
    }
};

int main()
{
    cout << "=====================Shape Composition=====================\n\n";
    int x1 = 3;
    int y1 = 7;

    int x2 = 6;
    int y2 = 8;

    int x3 = 8;
    int y3 = 5;

    int reduis = 10;

    Rectangle rectangle(x1,y1, x2,y2);
    Circle circle(x1, y1);
    Tringle tringle(x1,y1,  x2, y2, x3, y3);

    return 0;
}