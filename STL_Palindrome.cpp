#include <iostream>
#include <algorithm>
#include <deque>

template <typename T>
void display(const std::deque<T> &deq){
    std::cout<<"[";
    for(const auto &elem:deq)
        std::cout<<elem<<" ";
    std::cout<<"]"<<std::endl;
}

bool Palindrome(const std::string &d){
    std::deque<char> chr;
    for(char c:d)
        if(std::isalpha(c))
            chr.push_front(c);
    
    char c1{}, c2{};

    while (chr.size()>1){
        c1 = d.front();
        c2 = d.back();
        chr.pop_front();
        chr.pop_back();

        if(c1 != c2){
            std::cout<<"Not a palindrome"<<std::endl;
            return false;
        }
    }
    std::cout<<"Palindrome"<<std::endl;
    return true;
}

int main(){
    Palindrome("aabaa");
    Palindrome("abcde");

    return 0;
}