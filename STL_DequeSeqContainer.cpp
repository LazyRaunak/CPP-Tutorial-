/* It is a double ended container whose size is dynamic. The elements are not stored in contiguous memory. 
   It allows insertion & deletion at the back as well as at front. Inserting element other than at back/front
   is inefficient.
*/

#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

template <typename T>
void display(const std::deque<T> &d ){
    std::cout<<"[";
    for(const auto &elem:d)
        std::cout<<elem<<" ";
    std::cout<<"]"<<std::endl;
}

void Test1(){
  std::cout<<"-------------In Test 1-------------"<<std::endl;
  std::deque<int> d{1, 2, 3, 4, 5};
  display(d);

  d = {10, 20, 30, 40};
  display(d);

  std::deque<int> d1(10, 100);
  display(d1);
}

void Test2(){
  std::cout<<"-------------In Test 2-------------"<<std::endl;
  std::deque<int> d{1, 2, 3, 4, 5, 6};
  display(d);

  d.push_back(20);
  display(d);

  d.push_front(30);
  display(d);

  std::cout<<"Front element: "<<d.front()<<std::endl;
  std::cout<<"Back element: "<<d.back()<<std::endl;
  std::cout<<"Size of deque: "<<d.size()<<std::endl;

  d.pop_back();
  d.pop_front();
  display(d);
}

void Test3(){
    std::cout<<"-------------In Test 3-------------"<<std::endl;
    std::deque<int> d{1, 2, 3, 4, 5, 6, 7};
    display(d);
    std::deque<int> vec;

    for(const auto &elem:d){
        if(elem %2 == 0)
            vec.push_back(elem);
        else
            vec.push_front(elem);
    }
    display(vec);
}

void Test4(){
    std::cout<<"-------------In Test 4-------------"<<std::endl;
    std::deque<int> d{2, 4, 6, 8, 10};
    display(d);
    std::deque<int> deq;

    for(const auto &elem:d)
        deq.push_front(elem);
    display(deq);

    deq.clear();
    display(deq);           
}

void Test5(){
    std::cout<<"-------------In Test 5-------------"<<std::endl;
    std::deque<int> d{1, 2, 3, 4, 5};
    display(d);

    std::deque<int> deq;
    std::copy(d.begin() +2, d.end(), std::front_inserter(deq));
    display(deq);
}

int main(){
    // Test1();
    // Test2();
    // Test3();
    // Test4();
    Test5();

    return 0;
}