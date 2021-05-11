#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

void Test1(){
    std::array<int, 5> arr{1, 2, 3, 4, 5};

    int *ptr = arr.data();
    std::cout<<*ptr<<std::endl;
    std::cout<<ptr<<std::endl;

    *(ptr + 1) = 1000;
    std::cout<<*ptr<<std::endl;
    std::cout<<ptr<<std::endl;

    std::cout<<arr[1]<<std::endl;
}

void Test5(){
    std::array <int, 5> arr1{2, 4, 3, 1, 5};
    std::array <int, 5>::iterator minNum = std::min_element(arr1.begin(), arr1.end());
    auto maxNum = std::max_element(arr1.begin(), arr1.end());
    std::cout<<"Min: "<<*minNum<<", Max: "<<*maxNum<<std::endl;
}

int main(){
    Test1();
    Test5();

    return 0;
}