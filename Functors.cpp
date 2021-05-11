#include <iostream>

using namespace std;

class Print
{
    public:
        double operator()(double x)
        {
            return x*x;
        }
};

int main()
{
    Print p;
    cout<<p(3)<<endl;
    return 0;
}