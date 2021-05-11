#include <iostream>

using namespace std;

class Base{
    public:
        virtual void print() const{
            cout<<"In Base Class"<<endl;
        }
        virtual ~Base() {};
};

class Derived:public Base{
    public:
        virtual void print() const override final{ /*override keyword helps in throwing error if the function 
                                                    is not properly overriden or "check" that you are not 
                                                    altering/adding new methods that you think are overrides.*/

                                                    /*final keywords helps preventing in further inheritance of overriden 
                                                    function in derived classes of this class*/
            cout<<"In Derived class"<<endl;
        }
        virtual ~Derived() {};

};

// class Rederived:public Derived{
//     public:
//         virtual v    oid print() const override{ //compiler error  - can't overrride
//             cout<<"In Rederived class"<<endl;
//         }
// };

int main(){
    Base *b;
    Derived d;
    b = &d;

    d.print();

    return 0;
}