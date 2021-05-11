#include <iostream>
#include <vector>

using namespace std;

class Account{
    public:
        virtual void withdraw(){
            cout<<"In Account class"<<endl;
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
        virtual  ~Checking(){
            cout<<"Checking destructor"<<endl;
        }
};

class Savings:public Account{
    public:
        virtual void withdraw(){
        cout<<"In Savings class"<<endl;
        }
        virtual ~Savings(){
            cout<<"Savings destructor"<<endl;
        }
};

int main(){
    Account *p1 = new Account();
    Account *p2 = new Checking();
    Account *p3 = new Savings();
    
    p1->withdraw();
    p2->withdraw();
    p3->withdraw();

    cout<<"\n----------------Array----------------\n";
    Account *array[] = {p1, p2, p3};
    for(int i=0; i<3; i++){
        array[i]->withdraw();
    }

    cout<<"\n----------------Array----------------\n";
    array[0] = p3;   
    for(int i=0; i<3; i++){
        array[i]->withdraw();
    }

    cout<<"\n----------------Vector----------------\n";
    vector <Account *> account {p1, p2, p3};
    for(auto accPtr:account)
        accPtr->withdraw();

    cout<<"\n----------------Destructor----------------\n";
    delete p1; //Account destructor
    delete p2; //Account destructor if destructor not called virtually
    delete p3; //Account destructor if destructor not called virtually

    return 0;
}