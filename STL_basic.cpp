#include <iostream>
#include <algorithm>
#include <vector>

#define MAX(a,b) ((a>b)?a:b)  //Macros 

using namespace std;

int main(){
    vector<int> v{1, 2, 4, 5, 8};

    //sorting
    sort(v.begin(), v.end());
    for(auto element: v)
        cout<<element<<endl;
    
    //reversing
    reverse(v.begin(), v.end());
    for(auto element: v)
        cout<<endl<<element<<endl;
    
    //Generic programming for finding max between 2 characters, int, double, etc.
    cout<<MAX(10, 20)<<endl;
    cout<<MAX(10.67, 10.66)<<endl;
    cout<<MAX('a' , 'b')<<endl;

    return 0;
}

