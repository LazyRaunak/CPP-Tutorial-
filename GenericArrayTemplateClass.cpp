//use std::array whenever possible which is a template based-STL class.
#include <iostream>

using namespace std;

template <typename T, int N>
class Array{
    private:
        int size{N};
        T values[N];

        friend ostream &operator<<(ostream &os, const Array <T, N> &arr){
            os<<"[";
            for(const auto &val:arr.values)
                os<<val<<" ";
            os<<"]"<<endl;
            return os;
        }
    
    public:
        Array() = default;
        Array(T initVal){
            for(auto &item:values)
                item = initVal;
        }

        void fill(T val){
            for(auto &item:values)
                item = val;
        }

        int getSize() const{
            return size;
        }

        T &operator[] (int index){
            return  values[index];
        }
};

int main(){
    Array<int, 5>nums;
    std::cout<<"Num size is: "<<nums.getSize()<<endl;
    cout<<"Nums: "<<nums<<endl;

    nums.fill(0);
    std::cout<<"Num size is: "<<nums.getSize()<<endl;
    cout<<"Nums: "<<nums<<endl;

    nums.fill(10);
    cout<<"Nums: "<<nums<<endl;

    nums[3] = 1000;
    nums[4] = 3000;
    cout<<"Nums: "<<nums<<endl;

    Array<string, 10> strings(string{"Shera"});
    cout<<"strings size is: "<<strings.getSize()<<endl;
    cout<<strings<<endl;

    return 0;
}