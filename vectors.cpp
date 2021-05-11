#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector <char> vowels{'a', 'e', 'i', 'o', 'u'};
    cout<<vowels[0]<<'\n';
    cout<<vowels.at(1)<<endl;
    vowels.push_back('A');
    cout<<vowels[5]<<'\n';

    return 0;
}