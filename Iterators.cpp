#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

void display(const std::vector<int> &vec){
    std::cout<<"[";
    for (auto const &i:vec)
        std::cout<<i<<" ";
    std::cout<<"]"<<std::endl;
}

void test1(){
    std::cout<<"-------------------------Test1-------------------------"<<std::endl;
    std::vector<int>nums1{1, 2, 3, 4, 5};
    auto it = nums1.begin();
    std::cout<<*it<<std::endl;

    it++;
    std::cout<<*it<<std::endl;
}

void test2(){
    std::cout<<"-------------------------Test2-------------------------"<<std::endl;
    std::vector<int> nums1{1, 2, 3, 4, 5};
    std::vector<int>::iterator it = nums1.begin();
    while(it != nums1.end()){
        std::cout<<*it<<std::endl;
        it++;
    }
}

void test3(){
    std::cout<<"-------------------------Test3-------------------------"<<std::endl;
    std::vector<int> nums3{1, 2, 3, 4, 5};
    std::vector<int>::const_iterator it = nums3.begin();
    while(it != nums3.end()){
        std::cout<<*it<<std::endl;
        it++;
    }
}

void test4(){
    std::map<std::string, std::string>name{
        {"Raunak", "C++"},
        {"Mom", "Teacher"},
        {"Shreya", "student"}
    };
    auto i = name.begin();
    while(i != name.end()){
        std::cout<<i->first<<" : "<<i->second<<std::endl;
        i++;
    }
}

int main(){
    test1();
    test2();
    test3();
    test4();

    return 0;
}