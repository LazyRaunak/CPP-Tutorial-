#include <iostream>

using namespace std;

int main(){
    int miles{};
    int gallons{};
    double milesPerGallon{};

    cout<<"Enter the miles: ";
    cin>>miles;
    cout<<"Enter the gallons: ";
    cin>>gallons;

    try{
        if(gallons == 0)
            throw 0; //std practice is to use objects here
    
        // milesPerGallon = miles/gallons; Here, 22/0 throws exception
        milesPerGallon = static_cast<double>(miles)/gallons; //Here, 22/0 shows "Result: inf"
        
        cout<<"Result: "<<milesPerGallon<<endl;
    }

    catch(int &ex){ //best practice is to catch using reference
        cerr<<"Can't divide by zero."<<endl;
    }

    return 0;
}