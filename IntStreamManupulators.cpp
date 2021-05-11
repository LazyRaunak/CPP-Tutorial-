#include <iostream>

using namespace std;

int main(){
    int num{1};

    // noshowbase;
    //nouppercase;
    cout<<showbase<<uppercase;
    cout<<dec<<num<<" in decimal"<<endl;
    cout<<hex<<num<<" in hexa-decimal"<<endl;
    cout<<oct<<num<<" in octal"<<endl;
    cout<<dec<<showpos<<num<<" showing up sign of num"<<endl; //noshowpos

    return 0;
}