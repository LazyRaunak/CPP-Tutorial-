#include <iostream>

using namespace std;

class Point
{
    private:
        int x, y;
    
    public:
        Point(int xVal, int yVal)
        {
            x = xVal;
            y = yVal;
        }

        Point(const Point &p1)
        {
            x = p1.x;
            y = p1.y;
        }

        int getX()
        {
            return x;
        }

        int getY()
        {
            return y;
        }
};

int main()
{
    Point p1(10, 15);
    Point p2 = p1; //Copy constructor is called here
}