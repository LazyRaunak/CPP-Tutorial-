#include <iostream>
#include <vector>

using namespace std;

class Printable{
    friend ostream &operator <<(ostream &os, const Printable &printable);
    public:
        virtual void print(ostream &os) const = 0;
};

ostream &operator <<(ostream &os, const Printable &printable){
    printable.print(os);
    return os;
}
class Account:public Printable{
    public:
        virtual void withdraw(){
            cout<<"In Account class"<<endl;
        }

        virtual void print(ostream &os) const{
            os<<"Account display"<<endl;
        }

        virtual ~Account(){
            cout<<"Account destructor"<<endl;
        }
};

class Checking:public Account{
    public:
        virtual void withdraw(){
            cout<<"In Checking class"<<endl;
        }

        virtual void print(ostream &os) const{
            os<<"Checking display"<<endl;
        }

        virtual  ~Checking(){
            cout<<"Checking destructor"<<endl;
        }
};

class Savings:public Account{
    public:
        virtual void withdraw(){
        cout<<"In Savings class"<<endl;
        }

        virtual void print(ostream &os) const{
            os<<"Savings display"<<endl;
        }

        virtual ~Savings(){
            cout<<"Savings destructor"<<endl;
        }
};

int main(){
    Account *a1 = new Account();
    cout<<*a1<<endl;

    Account *a2 = new Checking();
    cout<<*a2<<endl;

    return 0;
}