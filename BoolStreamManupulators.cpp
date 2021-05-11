#include <iostream>
#include <iomanip> //Must include for manipulators

using namespace std;

int main(){
    cout<<"Default boolean type"<<endl;
    cout<<"No boolalpha default(10 == 10): "<<(10 == 10)<<endl;
    cout<<"No boolalpha default(10 == 20): "<<(10 == 20)<<endl;

    //Set to true/false formatting
    cout<<boolalpha;
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Boolean type by boolalpha method setting to true/false formatting"<<endl;
    cout<<"Boolalpha (10 == 10): "<<(10 == 10)<<endl;
    cout<<"Boolalpha (10 == 20): "<<(10 == 20)<<endl;

    cout<<noboolalpha; //sets back to 0/1
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Boolean type by noboolalpha method setting back to 0/1 formatting"<<endl;
    cout<<"No boolalpha (10 == 10): "<<(10 == 10)<<endl;
    cout<<"No boolalpha (10 == 20): "<<(10 == 20)<<endl;

    //cout<<boolalpha;
    cout.setf(ios::boolalpha); //set back to true/false using setf method
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Boolean type by setf method setting back to true/false formatting"<<endl;
    cout<<"Back to boolalpha (10 == 10): "<<(10 == 10)<<endl;
    cout<<"Back to boolalpha (10 == 20): "<<(10 == 20)<<endl;

    cout<<resetiosflags(ios::boolalpha); //reset to default which is 0/1
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Boolean type by setf method setting back to true/false formatting"<<endl;
    cout<<"Back to boolalpha (10 == 10): "<<(10 == 10)<<endl;
    cout<<"Back to boolalpha (10 == 20): "<<(10 == 20)<<endl;    

    return 0;
}