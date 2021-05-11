#include <iostream>

using namespace std;

class AccountInside{ //defining methods inside the class declaration
    private:
    double balance;

    public:
        void set_bal(double bal)
        {
            balance = bal;
        }
        double get_bal()
        {
            return balance;
        }
};

class AccountOutside{
    private:
        double balance;

    public:
        void set_bal(double bal);
        double get_bal();
};

void AccountOutside::set_bal(double bal){ //defining methods outside the class declaration
    balance = bal;
}

double AccountOutside::get_bal(){
    return balance;
}

int main()
{
    return 0;
}