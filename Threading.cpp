#include <iostream>
#include <thread>

using namespace std;

void foo(int y)
{
    cout<<"Threading using function: "<<y<<endl;
}

class threadObj
{
    public:
    void operator()(int x)
    {
        cout<<"Threading using objects: "<<x<<endl;
    }
};

int main()
{
    
    thread t1(foo, 3);
    thread t2(threadObj(), 4);

    cout<<"Threading..."<<endl;
    t1.join();
    t2.join();

    return 0;
}