#include <iostream>

using namespace std;

void double_data (int *);

int main()
{
    int val{10};
    int *int_ptr{nullptr};

    cout<<"Value of val is: "<<val<<endl;
    double_data(&val); 
    cout<<"Updated value of val is: "<<val<<endl;

    int_ptr = &val;
    double_data(int_ptr);
    cout<<"Updated data of int_ptr is: "<<val<<endl;
    return 0;
}

    void double_data(int *val){
        *val *= 2;
    }
