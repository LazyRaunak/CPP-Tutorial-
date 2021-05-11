/*Vectors can expand & contract as needed. The elements are stored in contiguous memory as an array.
  Vectors provide fast direct access in constant time. It allows rapid insertion & deletion at the back 
  of the vector in constant time while inserting elements into any other part other than back is not efficient.
  It happens in linear time, i.e., time increases with size.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Person{
  friend std::ostream &operator<<(std::ostream &os, const Person &p);
  std::string name;
  int age;

  public:
    Person() = default;
    Person(std::string nameVal, int ageVal)
      :name{nameVal}, age{ageVal} {};

    bool operator<(const Person &rhs)const{
      return this->age<rhs.age;
    }

    bool operator==(const Person &rhs) const{
      return(this->name == rhs.name && this->age == rhs.age);
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p){
  os<<p.name<<":"<<p.age<<std::endl;
  return os;
}

void display(const std::vector<int> &vec){
  std::cout<<"[";
  std::for_each(vec.begin(), vec.end(), [](int x){
    std::cout<<x<<" ";
    std::cout<<"]"<<std::endl;
  });
}

template <typename T>
void displayUsingT(const std::vector<T> &vec){
  std::cout<<"[";
  for(const auto &elem:vec)
    std::cout<<elem<<" ";
  std::cout<<"]"<<std::endl;
}

void Test1(){
  std::cout<<"-------------In Test 1-------------"<<std::endl;
  std::vector<int> vec1 {1, 3, 5, 7, 9};
  std::vector<int> vec2 (5, 100);
  std::vector<std::string> vec3{ std::string ("Raunak"), "Shreya", std::string("Iron Man")};

  vec2 = {3, 5, 4};
  std::ostream &operator<<(std::ostream &os, void Test1());
  std::cout<<"Size: "<<vec2.size()<<std::endl;
  std::cout<<"Capacity: "<<vec2.capacity()<<std::endl;
  std::cout<<"Max size: "<<vec2.max_size()<<std::endl;

  vec2.shrink_to_fit();
  std::cout<<"Capacity after shrinking: "<<vec2.capacity()<<std::endl;
  vec2.reserve(10);
  std::cout<<"Capacity after reserving: "<<vec2.capacity()<<std::endl;

  std::cout<<"vec.at(0): "<<vec2.at(0)<<std::endl;
  std::cout<<"vec[0]: "<<vec2[0]<<std::endl;
  std::cout<<"Front element: "<<vec2.front()<<std::endl;
  std::cout<<"Last element: "<<vec2.back()<<std::endl;

  std::cout<<"Is vector empty? "<<std::boolalpha<<vec2.empty()<<std::endl;
  std::cout<<"Swapping vector 1 & 2 "<<std::endl; 
  vec1.swap(vec2);/*Swappinig is only possible if 
  both type of vetors has same type of elemnts regardless of their size.*/
  displayUsingT(vec1);
  displayUsingT(vec2);

  auto findPos = std::find(vec1.begin(), vec1.end(), 5);
  vec1.insert(findPos, 100);
  std::cout<<"Inserting after 100"<<std::endl;
  displayUsingT(vec1);
  //std::insert(findPos, vec2.begin(), vec2.end());
}

void Test2(){
  std::cout<<"-------------In Test 2-------------"<<std::endl;
  std::vector<Person> stooges;
    Person p1{"Raunak", 26};
    displayUsingT(stooges);

    stooges.push_back(p1);
    displayUsingT(stooges);

    stooges.push_back(Person{"Shreya", 20});
    displayUsingT(stooges);

    stooges.emplace_back(Person{"Family", 1000});
    displayUsingT(stooges);
}

void Test3(){
  std::cout<<"-------------In Test 3-------------"<<std::endl;
  std::vector<int> vec{1, 3, 5, 2, 4};
  displayUsingT(vec);

  std::cout<<"Removing all element"<<std::endl;
  vec.clear();//remove all element;
  displayUsingT(vec);

  vec = {1, 2, 3, 4, 5, 6, 7, 8};
  std::cout<<"Erasing elements"<<std::endl;
  vec.erase(vec.begin(), vec.begin() +2);
  displayUsingT(vec);

  std::cout<<"Erasing all even nos."<<std::endl;
  vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it = vec.begin();
  while(it != vec.end()){
    if(*it %2 == 0)
      vec.erase(it);
    else
      it++;
  }
  displayUsingT(vec);
}

void Test4(){
  std::cout<<"-------------In Test 4-------------"<<std::endl;
  std::vector<int> vec1{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> vec2{50, 60};

  std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2),
    [](int x){
      return (x%2 == 0);
    });
    displayUsingT(vec1);
    displayUsingT(vec2);

  std::cout<<"Front element of vector: "<<vec1.front()<<std::endl;
}

int  main(){
  Test1();
  Test2();
  Test3();
  Test4();

  return 0;
}