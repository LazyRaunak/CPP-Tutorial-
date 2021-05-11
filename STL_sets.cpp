/* Sets are collection of objects that allow fast retrieval using a key. 
   It is usually implemented as binary tree or hashsets. Operation are comparatively very efficient.
   Sets are of 4 types:
       -std::set -> Often used
       -std::unordered_set
       -std::multiset
       -std::unordered_multiset
   
   std::set
   -They are ordered by key.
   -No duplicate elements are allowed.

   std::multi_set
   -They are defined in the same header file <set>
   -It allows duplicate elements in the set.

   std::unordered_set
   -They are defined in the #include <unordered_set>
   -Elements are unordered
   -No duplicate elements are allowed
   -Elements cannot be modified. They can be erased and then new elements can be inserted.
   -No reverse iterators are allowed.

   std::unordered_multiset
   -They are also defined in the #include <unordered_set>
   -Elements are unordered.
   -Allows duplicate elements
   -No reverse iterators are allowed.
*/

#include <iostream>
#include <set>
#include <string>
#include <iomanip> 

class Person{
    private:
        friend std::ostream &operator<<(std::ostream &os, const Person &p);
        std::string name;
        int age;
    
    public:
        Person() = default;
        Person(std::string nameVal, int ageVal)
            :name{nameVal}, age{ageVal} {};
        
        bool operator<(const Person &rhs)const{
            return (this->age<rhs.age);
        }

        bool operator==(const Person &rhs)const{
            return (this->age == rhs.age && this->name == rhs.name);
        }
};

std::ostream &operator<<(std::ostream &os, const Person &p){
    os<<p.name<<": "<<p.age;
    return os;
}

template <typename T>

void display(const std::set<T> &s){
    std::cout<<"[";
    for(const auto &elem:s)
        std::cout<<elem<<" ";
    std::cout<<"]"<<std::endl;
}

void Test1(){
    std::cout<<"------------------Set------------------"<<std::endl;
    std::set<int> s{1, 2, 9, 3, 4, 5, 1, 1, 2};
    
    std::cout<<"Set's size: "<<s.size()<<std::endl; //Counts 5 ->Repeatitive elements aren't counted.
    std::cout<<"Set's max size: "<<s.max_size()<<std::endl;
    
    s.insert(7); //No concept of back or front
    s.insert(4);
    display(s);

    s.erase(3);
    display(s);

    std::cout<<"Is 1 in the set: "<<s.count(1)<<std::boolalpha<<std::endl;
    std::cout<<"Is set empty?: "<<s.empty()<<std::endl;

    s.clear();
    std::cout<<"Is set empty?: "<<s.empty()<<std::endl;

    std::set<Person> p{
        {"Raunak", 26},
        {"Shreya", 20}
    };
    display(p);

    p.emplace("Mom", 53);
    display(p);

    auto it = p.find(Person{"Archana", 89});
    if(it != p.end())
        p.erase(it);
    display(p);

    std::set<std::string> str{"A", "B", "C"};
    str.insert("D");
    display(str);

    auto result = str.insert("R");

    std::cout<<std::boolalpha;
    std::cout<<"First: "<<*(result.first)<<std::endl;
    std::cout<<"Second: "<<result.second<<std::endl;
}

int main(){
    Test1();

    return 0;
}