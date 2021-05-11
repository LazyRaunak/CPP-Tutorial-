#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct City{
    string name;
    long population;
    double cost;
};

struct Country{
    string name;
    vector <City> cities;
};

struct Tours{
    string title;
    vector <Country> countries;
};

void ruler(){
    cout<<"12345678901234567890123456789012345678901234567890123456789012345678901234567890"<<endl;
}

int main(){
    Tours tours
    {
        "Tour ticket price from Miami",
        {
            {
                "Colombia",
                {
                    {
                        "Bogotia", 8787878, 400.98
                    },
                    {
                        "Cali", 2020202, 424.12
                    },
                    {
                        "Medellin", 2424242, 350.98
                    },
                    {
                        "Cartagena", 979797, 345.34
                    }
                },
            },
            {
                "Brazil",
                {
                    {
                        "Rio De Janerio", 13131313, 567.45
                    },
                    {
                        "Sau Paulo", 13131313, 975.45
                    },
                    {
                        "Salvador", 18181818, 855.49
                    }
                },
            },
            {
                "Chile",
                {
                    {
                        "Valdivia", 262626, 569.12
                    },
                    {
                        "Santiago", 7070707, 520.00
                    }
                }
            },
        }
    };

    ruler();

    cout<<setw(50)<<tours.title<<endl;

    cout<<setw(20)<<left<<"Country"
        <<setw(20)<<left<<"City"
        <<setw(15)<<right<<"Population"
        <<setw(15)<<right<<"Cost"<<endl;
    
    cout<<setw(70)<<setfill('-')<<""<<endl;
    cout<<setfill(' ');
    cout<<setprecision(2)<<fixed;

    for(auto country:tours.countries){
        for(int i=0; i<country.cities.size(); ++i){
            cout<<setw(20)<<left<<((i == 0)?country.name:"")
                <<setw(20)<<left<<country.cities.at(i).name
                <<setw(15)<<right<<country.cities.at(i).population
                <<setw(15)<<right<<country.cities.at(i).cost
                <<endl;
        }
    }
    cout<<endl<<endl;

    return 0;
}