#include <iostream>

using namespace std;

class Complex{
    private:
        int real, imag;
    
    public:
        // Complex(int r = 0, int i = 0)
        //     :real{r}, imag{i}{
        //     }

        Complex(int r = 0, int i =0)  {real = r;   imag = i;} 

        
        Complex operator + (Complex const &obj){ /*If we do operator overloading using classes, 
        we can pass one parameter, since the other one is taken into account using the 'this' operator, 
        but if we're using function, then we need to pass both the parameters if we are using binary operator*/
        
            Complex res;
            res.real = real + obj.real;
            res.imag = imag + obj.imag;
            return res;
        }

        void print(){
            cout<<real<<" +i"<<imag<<endl;
        }
};

int main(){
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; //ha -> c1.+(c2)
    c3.print();

    return 0;
}