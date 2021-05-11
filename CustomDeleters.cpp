/*Sometimes when we destroy a smart pointers, we need to destroy more than to just destroy the object on the heap.
    If we use custom deleters, we can't use make_shared() or make_unique() when we create smart pointers object
    since we need to provide custom deleters and these function don't support that. The basic idea is 
    if we need a specialized way to delete the objects, we need a specialized way to create them too.

    There're multiple ways to provide custom deleters. 2 of the ways are using:
    - Functions
    - Lambdas

    In case of a function, 
    we write a deleter function that'll be called automatically
    when smart pointer will be deleted. This function will be provided with a raw pointer to the managed object 
    that the smart pointer is referencing.
        
        Here, we're creating a deleter function that'll be passed in a raw pointer. In this case,
    it is a pointer to a test object and this pointer is managed by a smart pointer. In this function, 
    we're displaying a custom deleter and then we're deleting the raw pointer that was passed. 
    Now, when we create a smart pointer object 'ptr' as a shared pointer,
    we pass my_deleter in the initialization list. This also work in case of unique pointer.
        shared_ptr<My_Class> ptr {new My_Class{}, my_deleter};
    
    where my_deleter is defined as:
        void my_deleter(Test *ptr){ cout<<"In my custom deleter"<<endl; }
    
    
    In case of Lambda,
    Lambda is an anynomous function (function with no name) and can be defined inline where we want to use it.
    The code looks similar to that of my_deleter function. This code executes whenever pointer object is destroyed.
        
        shared_ptr<Data> ptr(new Test{100}, [] (Test *ptr){
            cout<<"In my custom deleter"<<endl;
            delete ptr
            });
*/

#include <iostream>
#include <memory>

using namespace std;

class Data{
    private:
        int data;
    public:
        Data()
            :data{0}{
                cout<<"No args Data constructor with value: "<<data<<endl;
            }
        
        Data(int dataVal)
            :data{dataVal}{
                cout<<"Single arg Data constructor with value: "<<data<<endl;
            }
        
        int getData() const{
            return data;
        }
        
        ~Data(){
            cout<<"Data destructor with val: "<<data<<endl;
        }
};

void myDelete(Data *ptr){
    cout<<"Custom function Deleter"<<endl;
    delete ptr;
}

int main(){
    cout<<"Using function:"<<endl;
    shared_ptr<Data> p1 {new Data{100}, myDelete};

    cout<<"Using Lambda:"<<endl;
    shared_ptr<Data> p2 (new Data{200}, [](Data *p2){
        cout<<"Custom Lambda deleter"<<endl;
        delete p2;
    });

    return 0;
}