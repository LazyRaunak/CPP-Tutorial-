#include <iostream>

using namespace std;

class Base{
    public:
        virtual void sayHello() const{
            cout<<"I'm a base class"<<endl;
        }
};

class Derived:public Base{
    public:
        virtual void sayHello(){
            cout<<"I'm a derived class"<<endl;
        }
};

void Greetings(const Base &obj){
    cout<<"Greetings: ";
    obj.sayHello();
}

int main(){
    Base b;
    Derived d;

    b.sayHello();
    d.sayHello();

    Greetings(b);
    Greetings(d);

    Base *ptr1 = new Base();
    ptr1->sayHello();

    Base *ptr2 = new Derived();
    ptr2->sayHello();

    delete ptr1;
    delete ptr2;

    return 0;
}