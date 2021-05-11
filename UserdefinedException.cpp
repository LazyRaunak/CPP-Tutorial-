#include <iostream>

using namespace std;

class DivideByZeroException{
};

class NegativeValueException{
};

double calcMPG(int, int);

int main(){
    int miles{0}, gallons{0};
    double MPG;

    cout<<"Enter miles & gallons: ";
    cin>>miles>>gallons;

    try{
        MPG = calcMPG(miles, gallons);
    }
    catch(DivideByZeroException &ex){
        cerr<<"Can't divide by zero"<<endl;
    }
    catch(NegativeValueException &ex){
        cerr<<"Values entered are negative"<<endl;
    }

    return 0;
}

double calcMPG(int miles, int gallons){
    if(gallons == 0)
        throw DivideByZeroException();

    if(miles<0 || gallons<0)
        throw NegativeValueException();
    
    return (static_cast<double> (miles)/gallons);
}