#include <iostream>

using namespace std;

class Base
{
    public:
        Base()
        {
            cout<<endl<<"Constructing base";
        }

        virtual ~Base() //if the Destructor is not virtual here, "Destructing Derived" is not called.
        {
            cout<<endl<<"Destructing base";
        }
};

class Derived: public Base
{
    public:
        Derived()
        {
            cout<<endl<<"Constructing Derived";
        }

        ~Derived()
        {
            cout<<endl<<"Destructing Derived";
        }
};

int main()
{
    Derived *d = new Derived();
    Base *b = d;
    delete b;

    return 0;
}