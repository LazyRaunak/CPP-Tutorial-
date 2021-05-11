#include<iostream>

using namespace std;

int main()
{
    int num1{}, num2{}, num3{};
    int summ{};
    cin>>num1>>num2>>num3;
    summ = (num1+num2+num3);
    cout<<"Round off average is: "<<summ/3<<endl;
    cout<<"Real average is: "<<static_cast<double>(summ)/3; //static_cast
    return 0;
}