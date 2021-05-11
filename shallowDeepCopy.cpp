#include <iostream>

using namespace std;

class Base{
    private:
        int val;
        int *ptrVal;
    
    public:
        //Base::Base()
        Base()
            :val{0}, ptrVal{new int(0)}{
            }
        
        Base(const Base &source){
            ptrVal = new int;
            *ptrVal = *source.ptrVal;
            val = source.val;
        }

        void setPtr(int ptr){
            *ptrVal = ptr;
        }

        void setVal(int valVal){
            val = valVal;
        }

        int getPtr(){
            return *ptrVal;
        }

        int getVal(){
            return val;
        }      
};

int main()
{
    Base b1;
    b1.setPtr(11);
    b1.setVal(15);

    Base b2;
    b2 = b1;
    b2.setPtr(50);
    b2.setVal(25);

    cout<<"b1 ptr: "<<b1.getPtr()<<endl;
    cout<<"b1 val: "<<b1.getVal()<<endl;
    cout<<"b2 ptr: "<<b2.getPtr()<<endl;
    cout<<"b1 ptr: "<<b2.getVal()<<endl;

    return 0;
}