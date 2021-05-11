#include <iostream>

using namespace std;

class Base{
    public:
        int a{0};
        void display(){
            cout<<a<<" , "<<b<<" , "<<c<<endl;
        }

    protected:
        int b{0};

    private:
        int c{0};
};

class Derived:public Base{
    public:
        void accessBaseMembers(){
            a=100;
            b=200;
            //c=300; Not Acessible
    }
};

int main(){
    Base base;
    base.a = 1000;
    //base.b = 2000; Compiler error
    //base.c = 3000;

    Derived der;
    der.a = 5000;
    //der.b = 6000; Compiler error
    //der.c = 7000;

    return 0;
}