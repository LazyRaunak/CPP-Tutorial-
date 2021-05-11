#include <iostream>
#include <vector>
#include <string>

using namespace std;

void swap (int *, int *);
void display (vector <string> *);

int main()
{
    int x{100}, y{200};
    vector <string> name{"Raunak", "Shreya"};

    swap(&x, &y);
    cout<<"The swapped val of x & y are: "<<x<<" & "<<y<<endl;

    display (&name);

    return 0;
}

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display (vector <string> *v)
{
    for(auto name: *v)
        cout<<"Name: "<<name<<endl;
}