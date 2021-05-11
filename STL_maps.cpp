/* Maps - Collection of stored objects that allow fast retreival using a key.
   4 tpes of map:
   -std::map
   -std::unordered_map
   -std::multimap
   -std::unordered_multimap

   Elements are stored as key value pairs using std::pair objects.
   Elements are ordered by key & no duplicate keys are allowed. Also, elements can be accessed using that key.

   std::multimap
   -It is contained in the <map> header file.
   -It allows duplicate elements

   std::unordered_map
   -They're defined in the header file <unordered_map>
   -No duplicate elements are allowed.
   -No reverse iterators are allowed.
*/

#include <iostream>
#include <map>
#include <set>

void display(std::map<std::string, std::set<int>> &m){
    std::cout<<"[";
    for(const auto &elem:m){
        std::cout<<elem.first<<":[ ";
        for(const auto &setElem:elem.second)
            std::cout<<setElem<<" ";
        std::cout<<"]";
    }
    std::cout<<"]"<<std::endl;
}

template <typename T1, typename T2>
void display(const std::map<T1, T2> &l){
    std::cout<<"[";
    for(const auto &elem:l){
        std::cout<<elem.first<<":"<<elem.second<<" ";
    }
    std::cout<<"]"<<std::endl;
}

void Test1(){
    std::cout<<"------------------Map------------------"<<std::endl;
    std::map<std::string, int> m{
        {"Raunak", 26},
        {"Jack", 48},
        {"Chris", 32}
    };
    display(m); //displayed in sorted order of keys which is string here

    m.insert(std::pair<std::string, int>("Robert", 50));
    display(m);

    m.insert(std::make_pair("John", 40));
    display(m);

    m["Rajpal"] = 42; //where "Rajpal" is the key name whose value is 42.
    display(m);

    m["Rajapal"] -= 4; //Update Rajpal's value by '-4'
    display(m);

    m.erase("John");
    display(m);

    std::cout<<"Count for Raunak: "<<m.count("Raunak")<<std::endl;
    std::cout<<"Count for John: "<<m.count("John")<<std::endl;

    auto it = m.find("Chris");
    if(it != m.end()){
        std::cout<<"Found "<<it->first<<":"<<it->second<<std::endl;
    }

    m.clear();
    display(m);
}

void Test2(){
    std::cout<<"------------------Map-Set------------------"<<std::endl;
    std::map<std::string, std::set<int>> grades{
        {"Jack", {50, 20}},
        {"Jill", {88, 56}},
        {"Huan", {56}}
    };
    display(grades);

    grades["Jill"].insert(54);
    display(grades);

    auto it = grades.find("Huan");
    if(it != grades.end()){
        it->second.insert(14);
    }
    display(grades);
}

int main(){
    Test1();
    Test2();

    return 0;
}