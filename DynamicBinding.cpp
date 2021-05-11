#include <iostream>

using namespace std;

class Base
{
    public:
        virtual void print()
        {
            cout<<"Printing in Base class"<<endl;
        }
};

class Derived: public Base
{
    public:
        void print()
        {
            cout<<"Printing in Derived class"<<endl;
        }
};

int main()
{
    Base b;
    Derived d;

    Base *bPtr = &b;
    bPtr->print();

    bPtr = &d;
    bPtr->print();

    return 0;
}