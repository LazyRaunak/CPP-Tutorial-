/* std::priority_queue
   -It is a container adapter just like stack & queue.
   -Allows insertions & removal of elements in order from the front of the container.
   -Elements are stored internally in vectors by default.
   -The data structure 'HEAP' is used behind the scenes (different heap than that used to store dynamic memory)
   -Elements are inserted in priority order, hence largest priority order element will be at front.
   -It is super efficient.
   -No iterators are supported.
   -They're initialized using <queue> header file.

   -Initialization
   std::priority_queue<int> pq; //vector by default
*/

#include <iostream>
#include <queue>

class Person{
    private:
        friend std::ostream &operator<<(std::ostream &os, Person &p);
        std::string name;
        int age;
    
    public:
        Person()
            :name{"Unknown"}, age{0} {};
        
        Person(std::string nameVal, int ageVal)
            :name{nameVal}, age{ageVal} {};
        
        bool operator<(const Person &rhs) const{
            return(this->age < rhs.age);
        }

        bool operator==(const Person &rhs) const{
            return(this->age == rhs.age && this->name == rhs.name);
        }
};

std::ostream &operator<<(std::ostream &os, Person &p){
    os<<p.name<<":"<<p.age;
    return os;
}

template <typename T>

void display(std::priority_queue<T> pq){
    std::cout<<"[ ";
    while(!pq.empty()){
        T elem = pq.top();
        pq.pop();
        std::cout<<elem<<" ";
    }  
    std::cout<<"]"<<std::endl;  
}

void Test1(){
    std::priority_queue<int> pq;
    for(int i:{3, 5, 7, 12, 23, 12, 4, 100, 0, 3, 5, 7})
        pq.push(i);
    
    std::cout<<"Size: "<<pq.size()<<std::endl;
    std::cout<<"Top: "<<pq.top()<<std::endl;

    display(pq);

    pq.pop();
    display(pq);
}

void Test2(){
    std::priority_queue<Person> pq;
    pq.push(Person{"A", 1});
    pq.push(Person{"E", 5});
    pq.push(Person{"L", 12});

    display(pq);
}

int main(){
    Test1();
    Test2();
    
    return 0;
}