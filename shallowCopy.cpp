#include <iostream>

using namespace std;

class Shallow{
    private:
        int *data;

    public:
        void setData(int d)
        {
            *data = d;
        }

        int getData()
        {
            return *data;
        }

        Shallow(int d);
        Shallow(const Shallow &source);

        ~Shallow();
};

Shallow::Shallow(int d){
    data = new int;
    *data = d;
}

Shallow::~Shallow(){
    delete data;
    cout<<"Freeing data"<<endl;
}

Shallow::Shallow(const Shallow &source)
    :data(source.data) {
        cout<<"Copy constructor"<<endl;
    }

void displayShallow(Shallow s)
{
    cout<<s.getData()<<endl;
}

int main()
{
    Shallow obj1{100};
    displayShallow(obj1);

    Shallow obj2{obj1};
    obj2.setData(1000);
    return 0;
}