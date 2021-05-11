#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ofstream outFile{"outFile.txt", ios::app};/*We're opening the file in truncation mode(default). So,
                                            it get erased whenever we run the program & write to it again.*/
    if(!outFile)
        cerr<<"Error creating file"<<endl;
    
    string line;
    cout<<"Enter here to write..."<<endl; 
    getline(cin, line);
    outFile<<line<<endl;

    outFile.close();

    /*copying file can be done in 2 ways:
    i- Copying line by line:
        while(getline inFile, line)
            outFile<<line<<endl;

    ii- Copying char by char
        char c;
        while(inFile.get(c))
            outFile.put(c);
    */
     
    return 0;
}