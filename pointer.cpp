/*  1. References are less powerful than pointers
    2. Once a reference is created, it cannot be made later to reference other object, while it is possible with pointers.
    3. References cannot be null, while pointers can be null.
    4. A Reference must be initialized when declared. Due to this, references in DS like Linked List, Tree, etc can not be used.
    5. Referneces are safer & easier to use.
    6. Constructors don't have a return type.
    7. Destructors can't be declared as static or constant & it does not have arguements. It should be declared within publi section of the class.
*/
#include <iostream>
#include <vector>

using namespace std;

void references()
{
    int *ptr;
    int &ref = *ptr; //can throws exception since the reference to a value at some random memory location
}

void PointerBasic()
{
    int *nullPointer{nullptr}; //initializing to point nowhere.
    int *ptr;
    int *ptr2 {nullptr};
    int val{10};
    
    ptr2 = &val;
    int *ptr3{&val};

    int arr[] {10, 20, 30};
    int *arrPtr{arr};
    
    cout<<"Value of ptr is: "<<*ptr<<endl;
    cout<<"Value of ptr2 is: "<<*ptr2<<endl;
    cout<<"Value of ptr3 is: "<<*ptr3<<endl;
    cout<<"Address of val is "<<arr<<endl;
    cout<<"Value of arr is: "<<*arr<<endl;
    cout<<"Address of arrPtr is "<<arrPtr<<endl;
    cout<<"Value of arrPtr is: "<<*arrPtr<<endl;
    cout<<"Address of nullPtr is: "<<&nullPointer<<endl;

    val = 100;
    cout<<"Updated value of ptr2 is: "<<*ptr2<<endl;   
}

class UseOfPointers
{
    public:
        string name = "Raunak";
        string College = "RTU";
        int ID = 49;

        void Swap(int &a, int &b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
};

void Swap1(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Print(const UseOfPointers &u) //Avoiding a copy of large structures. If we've passed it without reference, a new copy of it is created which causes wastage of CPU, time & memory.
{
    cout<<endl<<"ID: "<<u.ID<<", Name: "<<u.name<<", College Name: "<<u.College;
}

void modify() //use referencce in foreach loop to modify all the element
{
    vector <int> vec {10, 20, 30, 40}; 
    for(auto &inc: vec) //using rferences in each loop to avoid copy of multiple objects
    {
        inc += 5;
    }

    for(auto &num: vec)
    {
        cout<<endl<<num;
    }
}

int main()
{
    references();

    PointerBasic();

    int x = 10;
    // int y = 20;
    // int z = 30;
    // int a = 40;

    int *ptr;
    // int *ptr1;
    // int *ptr2;
    // int *ptr3;

    ptr = &x;
    // int *ptr1 = &y;
    // ptr2 = &z;
    // ptr3 = &a;

    int &ref = x;

    cout<<endl<<"Ptr: "<<ptr;    // Ptr: 0x23fe44
    cout<<endl<<"*Ptr: "<<*ptr;  //*Ptr: 10
    cout<<endl<<"ref: "<<ref;
    cout<<endl<<"&ref: "<<&ref;

    cout<<endl<<"++Ptr: "<<++ptr;  //++Ptr: 0x23fe48 - 4 bytes incremented
    cout<<endl<<"*(++Ptr): "<<*(++ptr); //*(++Ptr): 0

    UseOfPointers p;
    int a = 2, b = 3, c = 5;

    Swap1(a, b); //Modify the passed parameter in a function
    cout<<endl<<"a: "<<a<<", "<<"b: "<<b;

    p.Swap(b, c);
    cout<<endl<<"b: "<<b<<", "<<"c: "<<c;

    Print(p);

    modify();
    
    // Swap1(5, 6);

    // cout<<endl<<"Ptr1: "<<ptr1;
    // cout<<endl<<"*Ptr1: "<<*ptr1;

    // cout<<endl<<"Ptr2: "<<ptr2;
    // cout<<endl<<"*Ptr2: "<<*ptr2;
    // cout<<endl<<"++Ptr2: "<<++ptr2;
    // cout<<endl<<"*(++Ptr2): "<<*(++ptr2);

    // cout<<endl<<"Ptr3: "<<ptr3;
    // cout<<endl<<"*Ptr3: "<<*ptr3;
    // cout<<endl<<"++Ptr3: "<<++ptr3;
    // cout<<endl<<"*(++Ptr3): "<<*(++ptr3);

    return 0;
}