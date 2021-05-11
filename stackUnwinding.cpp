/*In the C++ exception mechanism, control moves from the throw statement to the first catch statement 
    that can handle the thrown type. When the catch statement is reached, all of the automatic variables 
    that are in scope between the throw and catch statements are destroyed in a process 
    that is known as stack unwinding.
*/

#include <iostream>

using namespace std;

void funcA();
void funcB();
void funcC();

void funcA(){
    cout<<"Starting function A"<<endl;
    try{
        funcB();
    }
    catch(string &ex){
        cout<<ex<<endl;
    }
    cout<<"Ending function A"<<endl;
}

void funcB(){
    cout<<"Starting function B"<<endl;
    try{
        funcC();
    }
    catch(string &ex){
        cout<<ex<<endl;
    }
    cout<<"Ending function B"<<endl;
}

void funcC(){
    cout<<"Starting function C"<<endl;
    throw (string{"Error!!!"});
    cout<<"Ending function C"<<endl;
}

int main(){
    try{
        funcA();
    }
    catch(string &ex){
        cout<<ex<<endl;
    }

    return 0;
}
