/* List are bi-directional.
   
   Forward list acts as a singly linked list, so the list can be traversed in only 1 direction.
   It has less overhead than List. 
   It allows rapid insertion & deletion of elements. 
   Like List, it also doesn't support direct element access.
   It has only front & NO back, hence no BACK methods available.
*/
#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <forward_list>
#include <iterator>

class Person{
    private:
        friend std::ostream &operator<<(std::ostream &os, const Person &p);
        std::string name;
        int age;
    
    public:
        Person()
            :name{"Unknown"}, age{0} {};
        
        Person(std::string nameVal, int ageVal)
            :name{nameVal}, age{ageVal} {};

        bool operator<(const Person &rhs) const{
            return this->age<rhs.age;
        }

        bool operator==(const Person &rhs) const{
            return(this->age == rhs.age && this->name == rhs.name);
        }
};

std::ostream &operator<<(std::ostream &os, const Person &p){
    os<<p.name<<": "<<p.age<<std::endl;
    return os;
}

template <typename T>

void display(const std::list<T> &li){
    std::cout<<"[";
    for(const auto &elem:li)
        std::cout<<elem<<" ";
    std::cout<<"]"<<std::endl;
}

template <typename T>

void displayForwardList(const std::forward_list<T> &fl){
    std::cout<<"[";
    for(const auto &elem:fl)
        std::cout<<elem<<" ";
    std::cout<<"]"<<std::endl;    
}

void Lists(){
    std::cout<<"-------------List-------------"<<std::endl;
    
    std::list<int> l{0, 1, 2, 3, 4, 5, 6};
    auto it = std::find(l.begin(), l.end(), 5);

    std::cout<<"Iterator position: "<<*it<<std::endl;

    if(it != l.end())
        l.insert(it, 100); //inserts 100 after 5
    display(l);

    l.erase(it); //erases 5
    display(l);

    l.resize(3); //resizes the array size to 3
    display(l);

    l.resize(5); //resizes to 5 by adding new elememts initializing as 0.
    display(l);

    l.push_back(500);
    display(l);

    l.push_back(100);
    display(l);

    l.clear();
    std::cout<<"Size of the list: "<<l.size()<<std::endl;

    std::list<Person> p;
    p.resize(5); //calls default constructor
    display(p);
}

void ForwardList(){
    std::cout<<"-------------Forward List-------------"<<std::endl;

    std::forward_list<int> fl{1, 2, 3, 4, 5, 6};
    std::cout<<"Front element: "<<fl.front()<<std::endl;
    std::cout<<"Max size of list: "<<fl.max_size()<<std::endl;

    fl.push_front(0);
    displayForwardList(fl);

    fl.pop_front();
    displayForwardList(fl);

    fl.emplace_front(0);
    displayForwardList(fl);

    auto it = std::find(fl.begin(), fl.end(), 4);
    fl.insert_after(it, 100);
    fl.emplace_after(it, 200);
    displayForwardList(fl);

    fl.sort();
    displayForwardList(fl);

    fl.erase_after(it);
    displayForwardList(fl);
}

int main(){
    Lists();
    ForwardList();

    return 0;
}