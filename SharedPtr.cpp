//Shared pointers provides shared ownership of heap objects.

/*Syntax - shared_ptr<T>

Properties:
    - It is not unique.
    - They can be copied or assigned.
    - We can have one heap object referenced by multiple shared pointers.
    - They can be moved too.
    - While unique pointers can be used to allocate arrays of address on the heap, shared pointers
        doesn't support this by default.
    - Since we've multiple shared pointers and all refrencing the same heap object, so in-order 
        to destroy that object we can use the most common way known as reference counting. 
        Everytime we instantiate a shared pointer object, and have it point/reference to the heap object 
        then we increment the counter. This counter simply has the number of shared pointers referencing that heap. When the reference count become zero, we know that nothing is referrig to the heap object and it can be safely destroyed.
*/

/*Shared pointer methods:
    - use_count() -> It returns the number of shared_ptr that're currently referring to the heap objects.
    - reset() -> decrement the use_count() by one. And in case of unique_   ptr, it destroys the heap object 
        and set the unique pointer to null.
    
    example:        
        shared_ptr<int> p1 {new int{100}};
        shared_ptr<int> p2{p1};
        p1.reset(); //we can't deallocate the integer on heap coz p2 is still referring to it. 
                      When p2 goes out of scope, the integer on the heap is de-allocated.

        p1.use_count(); // equals 0
        p2.use_count(); // equals 1
*/

//Shared pointers user definned class -> shared_ptr<Account> p1 {new Account{"Elon"}};

//Preferred way to create the shared pointers - shared_ptr<int> p1 = make_shared<int> 100;

#include <iostream>
#include <memory>

using namespace std;

class Data{
    private:
        int data;

    public:
        Data()
            :data{0}{
            cout<<"No args constructor called with val: "<<data<<endl;
        }

        Data(int dataVal)
            :data{dataVal}{
                cout<<"Single arg constructor called with val: "<<data<<endl;
            }
        
        ~Data(){
            cout<<"Destructor called with val: "<<data<<endl;
        }
};

void func(shared_ptr<Data> p){
    cout<<"Pointer use count: "<<p.use_count()<<endl;
}

int main(){
    shared_ptr<Data> p1{new Data{1001}};
    cout<<"Pointer 1 use count: "<<p1.use_count()<<endl;

    shared_ptr<Data> p2{p1};
    cout<<"Pointer 1 use count: "<<p1.use_count()<<endl;

    p1.reset();
    cout<<"Pointer 1 use count: "<<p1.use_count()<<endl;
    cout<<"Pointer 2 use count: "<<p2.use_count()<<endl;

    shared_ptr<Data> p3 = make_shared<Data>(2000);
    func(p3);
    cout<<"Pointer 3 use count: "<<p3.use_count()<<endl;

    shared_ptr<Data> p4 = p3;
    cout<<"Pointer 3 use count: "<<p3.use_count()<<endl;

    shared_ptr<Data> p5 = p3;
    cout<<"Pointer 3 use count: "<<p3.use_count()<<endl;
    
    p3.reset();
    cout<<"Pointer 3 use count: "<<p3.use_count()<<endl;

    return 0;
}