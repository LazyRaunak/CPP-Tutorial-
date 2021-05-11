#include <iostream>
#include <stack>
#include <queue>
#include <iomanip>
#include <vector>

bool isPalindrome(const std::string &s){
    std::stack<char> stk;
    std::queue<char> q;

    for(char c:s)
        if(std::isalpha(c)){
            c = std::toupper(c);
            stk.push(c);
            q.push(c);
        }
    
    char c1{};
    char c2{};

    while(!q.empty()){
        c1 = q.front();
        q.pop();

        c2 = stk.top();
        stk.pop();
        
        if(c1 != c2){
            //std::cout<<"Not a palindrome"<<std::endl;
            return false;
        }
    }
    //std::cout<<"Palindrome"<<std::endl;
    return true;           
}

int main(){
    std::vector<std::string> testString{"a", "Bob", "C++", "A toyota's toyota", "palindrome"};
    std::cout<<std::boolalpha;

    std::cout<<std::setw(10)<<std::left<<"Result"<<std::endl;
    std::cout<<"----------"<<std::endl;
    for(const auto &s: testString)
        std::cout<<std::setw(10)<<std::left<<isPalindrome(s)<<std::endl;
    std::cout<<std::endl;

    return 0;
}