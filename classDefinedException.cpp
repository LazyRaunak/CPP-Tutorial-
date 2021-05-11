#include <iostream>
#include <string>

using namespace std;

class IllegalBalanceException{
    public:
        IllegalBalanceException(){
            cout<<"User def exception"<<endl;
        };
        ~IllegalBalanceException(){};
};

class Account{
    private:
        string name;
        double balance;

    public:
        Account();
        Account(string, double);
        void deposit(double);
        void withdraw(double);

        ~Account();
};

Account::Account()
    :name{"Default user"}, balance{0.0}{
    cout<<"Account default constructor"<<endl;
}

Account::Account(string nameVal, double balanceVal)
    :name{nameVal}, balance{balanceVal}{
        if(balance<0)
            throw IllegalBalanceException();
    }

void Account::deposit(double amount){
    if (amount<0){
        cout<<"Can't deposit amount less than 0."<<endl;
    }
    else{
        balance += amount;
        cout<<"The updated balalnce is: "<<balance<<endl;
    }
}

void Account::withdraw(double amount){
    if (balance-amount>0){
        balance -= amount;
        cout<<"The updated balance after withdrawl is: "<<balance<<endl;
    }
    else{
        cout<<"Insufficient funds"<<endl;
    }
}

Account::~Account(){
    cout<<"Account default destructor"<<endl;
}

int main(){
    try{
        Account a1{"Raunak", -100};
    }
    catch(IllegalBalanceException &ex){
        cout<<"Couldn't create account with negative balance"<<endl;
    }


    return 0;
}