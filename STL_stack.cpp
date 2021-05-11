/* std::stack
   -It is last-in-First-out (LIFO) data structure.
   -All operation occurs on the top of the stack.
   -It is an adapter(allowing incompatible objects to collaborate) because it is implemented in terms of 
    already existing as STL containers. 
    
    e.g: std::stack <int> s; //default initialized as a deque.
         std::stack <int, std::vector<int>> s1;
         std::stack <int, std::deque<int>> s3;
         std::stack <int, std::list<int>> s2;
   -It can be implemented as a vector, list or deque.
   -Since adding & removing is done only from one end, iterators are not supported.
   -The header file used to implement stack is <stack>
*/

#include <iostream>
#include <stack>
#include <vector>
#include <list>

template <typename T>

void display(std::stack <T> s){
    std::cout<<"[ ";
    while(!s.empty()){
        T elem = s.top();
        s.pop();
        std::cout<<elem<<" ";
    }
    std::cout<<"]"<<std::endl;
}

int main(){
    std::stack<int> s;
    std::stack<int, std::vector<int>> s1;
    std::stack<int, std::deque<int>> s2;
    std::stack<int, std::list<int>> s3;

    for(int i:{1, 2, 4, 3, 5})
        s.push(i);
    display(s); //It makes a copy of the stack

    // s.push(100);
    // display(s);

    // s.top() = 1000; //modifies the top element of the stack
    // display(s);

    // s.pop();
    // s.pop();
    // display(s);

    // while(!s.empty()){ //This way clear method can be implemented in stack
    //     s.pop();
    // }
    // display(s);
    
    std::cout<<"Size of the stack: "<<s.size()<<std::endl;
}