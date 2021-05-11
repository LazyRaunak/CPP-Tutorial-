#include <iostream>

using namespace std;

double calcMPG(int, int);

int main(){
    int miles{0}, gallons{0};
    double MPG;

    cout<<"Enter the miles and gallons: ";
    cin>>miles>>gallons;

    try{
        MPG = calcMPG(miles, gallons);
        cout<<"Result: "<<MPG<<endl;
    }
    catch (int &ex){
        cerr<<"Divide by zero exception: "<<ex<<endl;
    }

    catch(string &ex){
        cerr<<ex<<endl;
    }

    return 0;
}

double calcMPG(int miles, int gallons){
    if(gallons == 0)
        throw 0;

    if(miles<0 || gallons<0)
        throw string{"Negative value error"};

    return (static_cast<double> (miles)/gallons);
}