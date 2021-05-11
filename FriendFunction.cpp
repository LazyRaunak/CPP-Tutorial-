#include <iostream>

using namespace std;

class Base
{
    private:
        int length;
    
    public:
        Base(): length{0} {}
    
        friend int printLength(Base);
};

int printLength (Base b)
{
    b.length += 10;
    return b.length;
}

class B;

class A
{
    int x;

    public:
        A(): x{0} {}

        void setData(int xVal)
        {
            x = xVal;
        }

        friend void max(A, B);
};

class B
{
    int y;

    public:
        void setData(int yVal)
        {
            y = yVal;
        }

        friend void max (A, B);
};

void max(A a, B b) //max is friendly to both classes that is max() function is accessible to private members of the classes.
{
    if(a.x >= b.y)
    {
        cout<<endl<<a.x;
    }
    else
    {
        cout<<endl<<b.y;
    }
}

int main()
{
    Base b;
    cout<<endl<<"The length of the box is: "<<printLength(b);

    A a1;
    B b1;

    a1.setData(10);
    b1.setData(20);

    max(a1, b1);

    return 0;
}