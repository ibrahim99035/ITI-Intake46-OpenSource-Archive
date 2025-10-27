#include <iostream>
using namespace std;

class Point{
    int x, y;
public:
    Point(int _x = 0, int _y = 0){
        x = _x;
        y = _y;
    }

    Point(Point &pointObj){
        x = pointObj.x;
        y = pointObj.y;
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
    Point* upperLeft;
    Point* lowerRight;
public:
    Rectangle(Point p1, Point p2): upperLeft(&p1), lowerRight(&p2) {}

    ~Rectangle(){
        cout<<"Rectangle Destroyed\n";
    }
};

class Circle{
    Point* center;
    int x, y;
    int reduis;
public:
    Circle(Point centerPoint): center(&centerPoint) {}

    ~Circle(){
        cout<<"Circle Destroyed\n";
    }
};

class Tringle{
    Point* topCorner;
    Point* rightCorner;
    Point* leftCorner;
public:
    Tringle(Point p1, Point p2, Point p3): topCorner(&p1), rightCorner(&p2), leftCorner(&p3) {}
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

    Point point1(x1, y1);
    Point point2(x2, y2);
    Point point3(x3, y3);

    int reduis = 10;

    Rectangle rectangle(point1, point2);
    Circle circle(point1);
    Tringle tringle(point1,point2,point3);

    return 0;
}
