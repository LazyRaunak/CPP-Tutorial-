#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double num1{654321.123456};
    double num2{123.456};
    double num3{12.0};

    cout<<setprecision(2);
    cout<<"---------------------- Setting precision to 2----------------------"<<endl;
    cout<<num1<<endl;
    cout<<num2<<endl;
    cout<<num3<<endl;

    cout<<setprecision(4);
    cout<<"---------------------- Setting precision to 4----------------------"<<endl;
    cout<<num1<<endl;
    cout<<num2<<endl;
    cout<<num3<<endl;

    cout<<setprecision(2)<<scientific;
    cout<<"---------------------- Setting precision to 2-scientific ----------------------"<<endl;
    cout<<num1<<endl;
    cout<<num2<<endl;
    cout<<num3<<endl;

    cout<<setprecision(2)<<fixed; //after decimal
    cout<<"---------------------- Setting precision to 2-fixed ----------------------"<<endl;
    cout<<num1<<endl;
    cout<<num2<<endl;
    cout<<num3<<endl;       
    
    cout.unsetf(ios::scientific);
    cout<<"---------------------- Setting scientific to default ----------------------"<<endl;
    cout<<num1<<endl;
    cout<<num2<<endl;
    cout<<num3<<endl;    
    
    cout<<setprecision(5)<<showpoint;
    cout<<"---------------------- Setting precision to 5 with trailing zeroes ----------------------"<<endl;
    cout<<num1<<endl;
    cout<<num2<<endl;
    cout<<num3<<endl;      
    return 0;
}