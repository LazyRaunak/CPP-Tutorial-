/*syntax: 
    template <typename T> or,
    template <class T>

E.g.:
    T max(T a, T b){
        return((a>b)?a:b);
    }

    max<int>(a, b); //The type written under <> tells the compiler that needs to generate 
                    a specialized function from the template that's created.

    max<double>(a, b); or,
    max(c, d);    //Often the compiler can deduce the type of the template parameter.

    //Template with classes
    Player p1{"Hero", 100, 20};
    Player p2{"Enemy", 99, 3};

    max<Player>(p1, p2);

    //Temmplates with function
    template <typename T1, typename T2>
    void func(T1 a, T2 b){
        cout<<a<<" "<<b;
    }

    func<int, double> (10, 20.2);
    func('A', 12.4);
*/

#include <iostream>
#include <string>

//using namespace std;

template <typename T>
T minM(T a, T b){
    return ((a<b)?a:b);
}

template <typename T1, typename T2>
void func(T1 a, T2 b){
    std::cout<<a<<", "<<b<<std::endl;
}

struct Person{
    std::string name;
    int age;

    bool operator<(const Person &rhs) const{
        return this->age<rhs.age;
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p){
    os<<p.name;
    return os;
}

template <typename T>
void mySwap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
} 

int main(){
    std::cout<< minM<int>(5, 9)<<std::endl;
    std::cout<< minM(2, 4)<<std::endl;
    std::cout<< minM('A', 'b')<<std::endl;

    Person p1{"Raunak", 26};
    Person p2{"Shera", 20};
    Person p3 = minM(p1, p2); /*This generates compiler error that no match for operator '<'
                                unless we write line 51.*/
    std::cout<<p3.name<<" is younger"<<std::endl;

    func('A', 12.4);
    func(p1, p2); /*This generates an error that there's no match for operand '<<'
                    unless we write line 56.*/
    
    int x{100}, y{200};
    mySwap(x, y);
    std::cout<<x<<", "<<y<<std::endl;

    return 0;
}
