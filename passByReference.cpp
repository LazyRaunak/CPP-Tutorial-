#include<iostream>
#include<vector>

using namespace std;

void swap (int &a, int &b);
void printVectors (vector<int> v);

int main()
{
    int a{}, b{};
    // cout<<"Swapping 2 nos. using Pass by Reference"<<endl;
    // cout<<"Enter 2 nos.:"<<endl;
    // cin>>a>>b;

    // swap(a, b);
    // cout<<"The swapped nos. are"<<a <<" "<<b;

    vector <int> data{22,33,44,55,66};
    printVectors(data);
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a=b;
    b=temp;
}

void printVectors (vector<int> v){
    for(auto vec: v)
        cout<<vec<<endl;
}