#include <iostream>
#include <vector>
#include <list>
#include <cctype> //converting lower case to upper case
#include <string>
#include <algorithm>

class Person{
    private:
        int age;
        std::string name;
    
    public:
        Person() = default;
        Person(std::string nameVal, int ageVal)
            :name{nameVal}, age{ageVal}{
            }
        
        bool operator<(const Person &rhs){
            return this->age<rhs.age;
        }

        bool operator==(const Person &rhs){
            return (this->name == rhs.name && this->age == rhs.age);
        }
};

void findTest(){
    std::cout<<"---------------------Find---------------------"<<std::endl;
    std::vector<int> vec{1, 2, 3, 5, 6};
    auto loc = std::find(std::begin(vec), std::end(vec), 1);
    if(loc != std::end(vec))
        std::cout<<"Found the number at loc: "<<*loc<<std::endl;
    else
        std::cout<<"Location not found"<<std::endl;
}

void countTest(){
    std::cout<<"---------------------Count---------------------"<<std::endl;
    std::vector<int> vec{1, 2, 4, 5, 1, 3, 1};
    int num = std::count(vec.begin(), vec.end(), 1);
    std::cout<<"Count = "<<num<<std::endl;
}

void countIfTest(){
    std::cout<<"---------------------Count If---------------------"<<std::endl;
    std::vector<int> vec{1, 2, 3, 1, 5, 100, 4};
    int num = std::count_if(vec.begin(), vec.end(), [](int x) {
        return x%2 == 0;
        });
    std::cout<<num<<" are even nos."<<std::endl;

    num = std::count_if(vec.begin(), vec.end(), [](int x){
        return x%2 != 0;
    });
    std::cout<<num<<" are odd nos."<<std::endl;
}

void replaceTest(){
    std::cout<<"---------------------Replace---------------------"<<std::endl;
    std::vector<int> vec{1, 2, 3, 4, 3, 1, 8, 5};
    for(auto i:vec){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    std::replace(vec.begin(), vec.end(), 1, 1000);
        for(auto i:vec){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

void testAllOf(){
    std::cout<<"---------------------All of---------------------"<<std::endl;
    std::vector <int> vec{1, 2, 3, 4, 1, 4, 6, 22, 14, 4};
    if(std::all_of(vec.begin(), vec.end(), [](int x){
        return x>10;
    }))
    std::cout<<"All elements are greater than 10"<<std::endl;
    else{
        std::cout<<"All elements are not greater than 10"<<std::endl;
    }
}

int main(){
    findTest();
    countTest();
    countIfTest();
    replaceTest();
    testAllOf();

    return 0;
}