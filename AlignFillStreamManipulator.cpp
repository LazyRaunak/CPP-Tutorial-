#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void ruler(){
    cout<<"123456789012345678901234567890"<<endl;
}

int main(){
    double num1{12345.67890};
    int num2{1234};
    string hello{"Hello"};

    ruler();
    cout<<num1<<endl //default 6 precision
        <<num2<<endl
        <<hello<<endl;

    ruler();
    cout<<setw(5)<<num1<<endl
        <<setw(10)<<num2<<endl
        <<setw(15)<<hello<<endl;
    
    ruler();
    cout<<setw(10)<<left<<num1
        <<setw(10)<<left<<num2
        <<setw(10)<<left<<hello<<endl;

    ruler();
    cout<<setfill('-'); //setfill aplies if setw() is called, it fills the blank spaces with '-'
    cout<<setw(10)<<left<<num1
        <<setw(10)<<left<<num2
        <<setw(10)<<left<<hello<<endl;

    ruler();
    cout<<setw(10)<<left<<setfill('*')<<num1
        <<setw(10)<<left<<setfill('-')<<num2
        <<setw(10)<<left<<setfill('$')<<hello<<endl;

    return 0;
}