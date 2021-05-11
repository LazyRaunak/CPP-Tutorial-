#include <iostream>
#include <string>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int noOfWords(string str)
{
    stringstream s(str);
    string word;

    int cnt = 0;
    while(s>>word)
    {
        cnt ++;
    }   

    return cnt; 
}

void wordsCount(string str)
{
    map<string, int> m;
    stringstream s(str);
    string word;

    while(s>>word)
    {
        m[word]++;
    }

    map<string, int>::iterator itr;
    for(itr = m.begin(); itr != m.end(); itr++)
    {
        cout<<itr->first <<" -> " <<itr->second<<endl;
    }
}

int main()
{
    string str = "Raunak has a tank";
    cout<<endl<<"No of words is: "<<noOfWords(str);

    wordsCount("A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin)");
    return 0;
}