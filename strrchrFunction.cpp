#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

int main()
{
    char str[] = "Raunak has a tank";
    char * ch = strrchr(str, 'a');

    auto pos = ch - str + 1;
    cout<<endl<<"Pos of last index of 'a' is: "<<pos;

    string st = "Raunak has a tank";
    char destStr[10];

    string subst = st.substr(13, 4);
    
    cout<<endl<<"Substring: "<<subst;
    cout<<endl<<"String copied at destination is: "<<strcpy(destStr, str);

    return 0;
}