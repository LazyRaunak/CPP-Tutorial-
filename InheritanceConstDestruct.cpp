#include <iostream>
#include <string>

using namespace std;

class Base{
    private:
        int val;
    
    public:
        Base()
            :val{0}{
            cout<<"No args constructor called"<<endl;
        }

        Base(int value)
            :val{value}{
                cout<<"Base overloaded constructor called"<<endl;
            }
        
        Base(const Base &other)
            :val{other.val}{
                cout<<"Copy constructor called"<<endl;
            }
        
        Base &operator = (const Base &rhs){
            cout<<"Base operators ="<<endl;
            if(this == &rhs)
                return *this;
            val = rhs.val;
            return *this;
        }
        
        ~Base(){
            cout<<"Base destructor called"<<endl;
        }
};

class Derived:public Base{
    private:
        int doubledVal;
    public:
        // Derived()
        //     :doubledVal{0}{
        //         cout<<"No value Derived constructor called"<<endl;
        //     }
        
        // Derived(int value)
        //     :doubledVal{value*2}{
        //         cout<<"Derived overloaded constructor called"<<endl;
        //     }


        Derived()
            :Base{}, doubledVal{0}{
                cout<<"Base - Derived no args constructor called"<<endl;
            }
        
        Derived(int value)
            :Base{value}, doubledVal{value*2}{
                cout<<"Base - Derived overloaded constructor called"<<endl;
            }
        
        Derived(const Derived &source)
            :Base{source}, doubledVal{source.doubledVal}{
                cout<<"Derived copy constructor"<<endl;
            }
        
        Derived &operator = (const Derived &rhs){
            cout<<"Derived operator"<<endl;
            if(this == &rhs)
                return *this;
            Base::operator=(rhs);
            doubledVal = rhs.doubledVal;
            return *this;
            }
      
        ~Derived(){
            cout<<"Derived destructor called"<<endl;
        }
};

int main(){
    // Base b;
    // Derived d;

    // Base{100};
    // Derived{100};

    Derived d{100};
    Derived d1(d);
    d=d1;

    return 0;
}