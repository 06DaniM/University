#include <iostream>
using namespace std;

class Point1D
{
public:
    int x;
    void setX(int X) { x = X; }
};

class Point2D : public Point1D
{
public:
    int y;
    void setY(int Y) { y = Y; }
};

class Point3D : public Point2D
{
public:
    int z;
    void setZ(int Z) { z = Z; }
};

int main() 
{
    Point1D p1;
    p1.setX(1);
    cout << p1.x << endl;

    Point2D p2;
    p2.setX(2); p2.setY(2);
    cout << p2.x << " " << p2.y << endl;

    Point3D p3;
    p3.setX(3); p3.setY(3); p3.setZ(3);
    cout << p3.x << " " << p3.y << " " << p3.z << endl;

    return 0;
}
