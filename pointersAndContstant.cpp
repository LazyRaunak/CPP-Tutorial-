#include <iostream>

using namespace std;

int main()
{
    int hScore = 100;
    int lScore = 0;
    const int *ptr1{&hScore};
    int *const ptr2 {&hScore};
    const int *const ptr3 {&hScore};

    cout<<"Value of ptr1 is:"<<*ptr1<<endl;
    cout<<"Value of ptr2 is:"<<*ptr2<<endl;
    cout<<"Value of ptr3 is:"<<*ptr3<<endl;

    // *ptr1 = 0; will throw error
    ptr1 = &lScore;
    cout<<"Updated value of hPtr is:"<<*ptr1<<endl;

    *ptr2 = 0;
    //ptr2 = &lScore; will throw error
    cout<<"Updated value of ptr is:"<<*ptr2<<endl;

    //*ptr = 0; will throw error
    //ptr3 = &lScore; will throw error

    return 0;
}