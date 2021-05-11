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

void doWithdraw(Account &account){
    account.withdraw();
}

int main(){
    Account a;
    Account &ref1 = a;
    ref1.withdraw();

    Checking c;
    Account &ref2 = c;
    ref2.withdraw();

    Account acc;
    Savings sav;

    doWithdraw(acc);
    doWithdraw(sav);

    return 0;
}