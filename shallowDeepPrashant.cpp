#include <iostream>
#include <string.h>

class MyString{

public:
    char* str;
    int size;

    MyString(const char* str){
        size = strlen(str);
        this->str = new char[size+1];
        memcpy(this->str, str, size);
    }

    void display(){
        for (int i =0; i<size ; i++)
        {
            std::cout << str[i];
        }
        std::cout << "\n";
    }

    // overrdiving the copy constructor
    MyString(MyString& src){
        std::cout << "calling copy const" << std::endl;
        size  =  src.size;
        this->str = new char[size+1];
        memcpy(this->str, src.str, size);
    }

};

int main(){
    
    MyString s1("Raunak");
    s1.display();
    MyString s2 = s1;
    s2.display();

    s1.str[2] = 'U';
    s1.display();
    s2.display();
    return 0;

}