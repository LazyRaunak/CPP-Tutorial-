#include <iostream>
#include <exception>

using namespace std;

class IllegalBalanceException:public exception{
    public:
        IllegalBalanceException() noexcept = default; //noexcept keyword guarantees that no exception is being going to thrown from it.
        ~IllegalBalanceException() = default;

        virtual const char *what() const noexcept{
            return "Illegal balance exception";
        }        
};

class Account{
    private:
        string name;
        double balance;
    
    public:
        Account();
        ~Account();

        Account(string, double);
        void deposit(double);
        void withdraw(double);
};

Account::Account()
    :name{"Default"}, balance{0.0}{
        cout<<"Default constructor with no args."<<endl;
    }

Account::Account(string nameVal, double balanceVal)
    :name{nameVal}, balance{balanceVal}{
        if(balanceVal<0.0)
            throw IllegalBalanceException();
    }

void Account::deposit(double amount){
    if (balance<0)
        cout<<"Can't deposit amount less than 0."<<endl;
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
        cout<<ex.what()<<endl;
    }


    return 0;
}