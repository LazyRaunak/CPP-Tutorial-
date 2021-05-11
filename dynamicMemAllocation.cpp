#include <iostream>

using namespace std;

int main()
{
    int *ptr{};
    ptr = new int; //dynamically allocating memory - on heap
    cout<<"Value & address of ptr: "<<*ptr<<" "<<ptr<<endl;
    delete ptr; //frees the allocated storage
    cout<<"Value & address of ptr: "<<*ptr<<" "<<ptr<<endl;
    /*The allocated storage does not have a name, the only way to get to that is via pointer. If we loose the 
    pointer while reassigning or if it goes out of scope, then we loose the way to get to that storage and we 
    have a memory leak.*/

    int *arrayPtr{nullptr}; //dynamically allocating array
    int size{};

    cout<<"Enter the size of the array: ";
    cin>>size;
    arrayPtr = new int[size];
    delete [] arrayPtr;

    return 0;
}