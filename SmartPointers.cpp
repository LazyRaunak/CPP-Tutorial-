#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Data{
    private:
        int data;
    public:
        Data():
            data{0}{
                cout<<"Default constructor with no args having value: "<<data<<endl;
            }
        
        Data(int dataVal)
            :data{dataVal}{
                cout<<"Default constructor with 1 args having value: "<<data<<endl;
            }
        
        int getData() const{
            return data;
        }

        ~Data(){
            cout<<"Default destructor with having value: "<<data<<endl;
        }
};

//Function prototypes
unique_ptr<vector<shared_ptr<Data>>>make(); //or auto make();
void fill(vector<shared_ptr<Data>> &vec, int num);
void display(vector<shared_ptr<Data>> &vec);

unique_ptr<vector<shared_ptr<Data>>>make(){ //or auto make() {......}
    return unique_ptr<vector<shared_ptr<Data>>>();
}

void fill(vector<shared_ptr<Data>> &vec, int num){
    int temp;
    for(int i=1;i<=num;++i){
        cout<<"Enter data point ["<<i<<"]: ";
        cin>>temp;
        vec.push_back(make_shared<Data>(temp));
    }
}

void display(vector<shared_ptr<Data>> &vec){
    cout<<"Displaying vector data"<<endl;
    for(const auto &ptr:vec)
        cout<<ptr->getData()<<endl;
}

void SmartPointer()
{
    unique_ptr<int> valuePtr(new int(15));
    int x = 15;

    if(x == *valuePtr)
    {
        cout<<"Values matched!"<<endl;
    }
}

int main(){
    int num;

    SmartPointer();

    unique_ptr<vector<shared_ptr<Data>>> vecPtr;
    vecPtr = make();

    cout<<"Enter the number of data points: ";
    cin>>num;

    fill(*vecPtr, num);
    display(*vecPtr);

    return 0;
}