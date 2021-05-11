#include <iostream>

using namespace std;

double calcMPG(int, int);

int main(){
    int miles{0}, gallons{0};
    double MPG{0};

    cout<<"Enter the miles and gallons: ";
    cin>>miles>>gallons;

    try{
        MPG = calcMPG(miles, gallons);
        cout<<"Result: "<<MPG<<endl;
    }
    catch(int &ex){
        cout<<"Divide by zero error: "<<ex<<endl;
    }

    return 0;
}

double calcMPG(int miles, int gallons){
    if (gallons == 0)
        throw 0; /*if user imputs '0' for gallons, exception is thrown that "terminate called after 
        throwing an instance of 'int' " coz it is looking for an exception handler in the program. If it finds one, 
        then exception is handled oth the program terminates, so to avoid this we use a try catch block in the main() */
    return(static_cast<double>(miles)/gallons);
}