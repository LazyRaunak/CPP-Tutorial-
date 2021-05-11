/*
 -Objects cannot be instantiated from Abstract class
 -A class is abstract if it has at least one pure virtual function. 
 -If we do not override the pure virtual function in derived class, then derived class also becomes abstract class. 
 -We can use pointers & references to dynamically refer to create classes derived from them
*/

#include <iostream>
#include <vector>

using namespace std;

class Shape{
    public:
        virtual void draw() = 0; //pure virtual function
        virtual void rotate() = 0;
        virtual ~Shape() {}
};

class openShape:public Shape{ //Abstract class
    public:
        virtual ~openShape() {}
};

class closedShape:public Shape{
    public:
        virtual ~closedShape() {}
};

class Line:public openShape{
    public:
        virtual void draw() override{
            cout<<"Drawing a line"<<endl;
        }

        virtual void rotate() override{
            cout<<"Rotating a circle"<<endl;
        }

    virtual ~Line() {}
};

class Circle:public closedShape{
    public:
        virtual void draw() override{
            cout<<"Drawing a circle"<<endl;
        }

        virtual void rotate() override{
            cout<<"Rotating a circle"<<endl;
        }

        virtual ~Circle() {}
};

void screenRefresh(const vector <Shape*> &shapes){
    cout<<"Refreshing"<<endl;
    for(auto p: shapes){
        p->draw();
    }
}

int main(){
     //Shape s; Cannot instantiate an object of an abstract class since methods are pure virtual function
    //  Shape *p = new Shape(); 

     Circle c;  
     c.draw();

     Shape *ptr = new Circle();
     ptr->draw();
     ptr->rotate();

     return 0;

}