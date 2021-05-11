/* std::queue
   -It is First In First Out data structure.
   -It is an adapter class because it is implemented in terms of already existing STL containers.
   -It can be implemented as as a list or dequeue
   -Elements are pushed at the back & popped from the front.
   -No iterators are supported.

   Initialization
   -std::queue<int> q1; //by default initializes as deque
   -std::queue<int, std::list<int>> q2;  //list
   -std::queue<int, std::deque<int>> q3; //deque
*/

#include <iostream>
#include <queue>
#include <deque>
#include <list>

template <typename T>
void display(std::queue <T> q){
    std::cout<<"[ ";
    while(!q.empty()){
        T elem = q.front();
        q.pop();
        std::cout<<elem<<" ";
    }
    std::cout<<"]"<<std::endl;
}

int main(){
    std::queue<int> q;

    for(int i:{1, 2, 3, 4, 5})
        q.push(i);
    display(q);

    std::cout<<"Element at front: "<<q.front()<<std::endl;
    std::cout<<"Element at back: "<<q.back()<<std::endl;

    q.push(100);
    display(q);

    q.pop();
    q.pop();
    display(q);

    while(!q.empty()){
        q.pop();
    }
    display(q);

    std::cout<<"Element size: "<<q.size()<<std::endl;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    display(q);

    q.front() = 100;
    q.back() = 600;
    display(q);

    return 0;
}