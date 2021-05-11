#include <iostream>

using namespace std;

int *createArray (size_t t, int val = 0);
void displayArray (const int *const array, int size_t);

int main()
{
    size_t t{0};
    int val{0};
    int *myArray{nullptr};

    cout<<"Enter the size of the array: ";
    cin>>t;
    cout<<"Enter the value that needs to assigned: ";
    cin>>val;

    createArray(t, val);
    displayArray(myArray, t);

    return 0;
}

int *createArray(size_t t, int val)
{
    int *valStore{nullptr};
    for(int i{0}; i<t; i++)
        valStore[i+1] = val;
    cout<<"Values returned are: ";//<<*valStore;
    return valStore;
}

void displayArray(const int *const array, size_t t)
{
    for(int i{0}; i<t; i++)
        cout<<endl;
}