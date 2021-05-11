#include <iostream>

using namespace std;

class Base{
    public:
        void print(){
            cout<<"Base class print message"<<endl;
        }
        
        virtual void show(){
            cout<<"Base class show message"<<endl;
        }
};

class Derived:public Base{
    public:
        void print(){
            cout<<"Derived class print message"<<endl;
        }

        void show(){
            cout<<"Derived class show message"<<endl;
        }
};

int main(){
    Base *b;
    Derived d;
    b = &d;

    b->print();
    b->show();

    d.print();
    d.show();

    cout<<"-----------------------------"<<endl;

    Base *x = new Derived();
    x->show();

    return 0;
}