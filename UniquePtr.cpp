/*Unique Pointers
    - #include <Memory> header should be included
    - Points to an object og type T on the heap. unique_ptr<t>
    - Can't have multiple unique ptrs pointing to the same object on the heap.
    - Can't be copied or assigned
    - Can be moved
    - Object is automatically destroyed */

// Syntax - std::unique_ptr<int> p1 {new int {100}};

/* p1.reset() -> sets p1 to null pointer
User defined classes -> std::unique_ptr<Acount> p1 {new Account {"Elon"}};

Now, it can be used as a raw pointer
    - cout<<*p1<<endl;
    -p1->deposit(100);

Vectors -> vector<std::unique_ptr<int>> vec;
Move -> std::move(ptr)

In C++ 14, declaring unique ptr syntax 
    - std::unique_ptr<int> p1 = make_unique<int>(100);
    - std::unique_ptr<Account> p2 = make_unique<Account> ("Musk", 1000);
    - std::auto p3 = make_unique <Player> ("Sunil", 05); */

#include <iostream>
#include <memory>

using namespace std;

class Data{
    private:
        int data;
    public:
        Data()
            :data{0}{
                cout<<"Data constructor with no args: "<<data<<endl;
            }

        Data(int dataVal):
            data{dataVal}{
                cout<<"Data constructor with 1 arg: "<<data<<endl;
            }

        int getData() const{
            return data;
        }

        ~Data(){
            cout<<"Data destructor with arg value: "<<data<<endl;
        }
};


int main(){
    Data d1{1000};

    Data *d2 = new Data{2000}; //It needs to be deleted oth there's a memory leak.
    delete d2;

    unique_ptr<Data> d3 {new Data{3000}}; //smart pointers, deleted automatically
    
    unique_ptr<Data> d4 = make_unique<Data> (4000);

    unique_ptr<Data> d5;
    //d5 = d3; Can't initalize unique pointers as they're unique.

    //unique_ptr<Data> d6{d3}; will throw error.

    d5 = move(d3);

    if(d3){
        cout<<"t1 is not a null pointer"<<endl;
    }
    else{
        cout<<"t1 is a null pointer"<<endl;
    }

    return 0;
}