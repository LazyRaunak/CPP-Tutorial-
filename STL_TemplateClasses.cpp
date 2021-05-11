#include <iostream>
#include <string>
#include <vector>

template <typename T>

class Item{
    private:
        std::string name;
        T value;
    
    public:
        Item(std::string name, T value)
            : name{name}, value{value}{
            }
        
        std::string getName() const{
            return name;
        }

        T getValue() const{
            return value;
        }
};

template<typename T1, typename T2>
struct myPair{
    T1 first;
    T2 second;
};

int main(){
    Item<int> rent{"House", 3000};
    std::cout<<"Topic: "<<rent.getName()<<", Value: "<<rent.getValue()<<std::endl;

    Item<std::string> family{"Raunak", "Shreya"};
    std::cout<<"Topic: "<<family.getName()<<", Second member: "<<family.getValue()<<std::endl;

    // Item<std::string> profession{"Raunak", {"C++", "Developer"}};
    // std::cout<<"Topic: "<<profession.getName()<<std::endl
    //         <<"Technology: "<<profession.getValue().getName()<<std::endl
    //         <<"Postion: "<<profession.getValue().getValue()<<std::endl;
    
    std::vector<Item<double>>vec{};
    vec.push_back(Item<double>("Raunak", 25.9));
    vec.push_back(Item<double>("Shreya", 25.1));
    for(const auto &item:vec){
        std::cout<<"Name: "<<item.getName()<<", age: "<<item.getValue()<<std::endl;
    }

    myPair<std::string, int>p3{"Mom", 52};
    myPair<std::string, int>p4{"Dad", 63};
    std::cout<<"Name: "<<p3.first<<", Age: "<<p3.second<<std::endl;
    std::cout<<"Name: "<<p4.first<<", Age: "<<p4.second<<std::endl;

    return 0;
}