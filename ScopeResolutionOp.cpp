#include <iostream>

using namespace std;

int x = 10;

void num()
{
    int x = 20;
    cout<<"Num: "<<::x<<endl; //1) To access a global variable when there is a local variable with same name:

    cout<<"Num: "<<x<<endl;
}

class A
{
    public:
        void fun();
};

void A::fun() //2) To define a function outside a class.
{
    cout<<"Printing"<<endl;
}


class B
{
    static int x;
    public:
        static int y;

        void func(int x)
        {
            cout<<"The value of static x: "<<B::x<<endl;    //Accessing static memmber of a class.
        }
};

int B::y = 2;
int B::y = 4;

int main()
{
    int x = 15;
    num();

    A a;
    a.fun();

    return 0;
}