#include <iostream>
using namespace std;

class Point1D
{
public:
    int x;
    Point1D(int x_) : x(x_)
    {
        cout << "Ctor Point1D" << endl;
    }
    ~Point1D()
    {
        cout << "Ctor Point1D" << endl;
    }
};

class Point2D : public Point1D
{
public:
    int y;
    Point2D(int x_, int y_) : Point1D(x_), y(y_)
    {
        cout << "Ctor Point2D" << endl;
    }

    ~Point2D()
    {
        cout << "Ctor Point2D" << endl;
    }
};

class Point3D : public Point2D
{
public:
    int z;
    Point3D(int x_, int y_, int z_) : Point2D(x_, y_), z(z_)
    {
        cout << "Ctor Point3D" << endl;
    }

    ~Point3D()
    {
        cout << "Ctor Point3D" << endl;
    }
};

int main() 
{
    Point3D p(3, 5, 7);

    return 0;
}
