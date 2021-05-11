/*
These are the common escape sequences:

\a - Bell(beep)
\b - Backspace
\f - Formfeed
\n - New line
\r - Carriage Return
\t - Horizontal Tab
\\ - Backslash
\' - Single Quotation Mark
\" - Double Quatation Mark
\ooo - Octal Representation
\xdd - Hexadecimal Representaion
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    ifstream inFile{"myfile.txt"}; //open file
    string line, line1, line2, line3{};
    char c;
    int num{};
    double total{};

    // cout<<endl<<"-------------------Reading line by line-------------------"<<endl;
    // if(!inFile){ //check if file is open
    //     cerr<<"File open error"<<endl;
    //     return 1; //exit the program (main)
    // }

    // while(!inFile.eof()){ //while not at the end;
    //     getline(inFile, line); //read a line
    //     cout<<line<<endl; //display the line
    // }

    // cout<<endl<<"-------------------Reading character wise-------------------"<<endl;
    // cout<<"File is in open mode: "<<(inFile.is_open() == 1?"True":"False")<<endl;
    // cout<<"Printing by reading characters"<<endl;
    // while(inFile.get(c))
    //     cout<<c;
    
    cout<<endl<<"-------------------Reading by data types-------------------"<<endl;
    inFile>>num>>line1>>total;
    cout<<num<<endl;
    cout<<line1<<endl;
    cout<<total<<endl;

    inFile.close(); //close the file

    cout<<endl<<"-------------------Reading File 2-------------------"<<endl;

    ifstream inFile2{"File2.txt"};
    
    if (!inFile2)
    {
        cerr<<"Problem opening file"<<endl;
    }
    
    while(inFile2>>line>>num>>total){
        cout<<setw(10)<<left<<line
            <<setw(10)<<num
            <<setw(10)<<right<<total
            <<endl;
    }
    inFile.close();    
    return 0;
}