/* Weak pointer - It is a smart pointer that holds a non-owning/weak reference to an object 
    that is managed by shared pointers. it must be converted to shared pointers to access the referenced object.
    weak_ptr models only temporary ownership that is the object can be accessed only if it exists
    and it may be deleted anytime by someone else. 
    
    A good example would be a cache.
    For recently accessed objects, you want to keep them in memory, so you hold a strong pointer to them. 
    Periodically, you scan the cache and decide which objects have not been accessed recently. 
    You don't need to keep those in memory, so you get rid of the strong pointer.
    
    But what if that object is in use and some other code holds a strong pointer to it? 
    If the cache gets rid of its only pointer to the object, it can never find it again. 
    So the cache keeps a weak pointer to objects that it needs to find if they happen to stay in memory.
    
    This is exactly what a weak pointer does -- it allows you to locate an object if it's still around.
*/

#include <iostream>
#include <memory>

using namespace std;

class B; //forward declaration

class A{
    shared_ptr<B> p1;

    public:
        void setB(shared_ptr<B> &b){
            p1 = b;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
        }

        A(){
            cout<<"Constructor A"<<endl;
        }

        ~A(){
            cout<<"Destructor A"<<endl;
        }
};

class B{
    //shared_ptr <A> p2; make it weak to break the strong circular reference
    weak_ptr <A> p2;

    public:
        void setA(shared_ptr<A> &a){
            p2 = a;
        }

        B(){
            cout<<"Constructor B"<<endl;
        }

        ~B(){
            cout<<"Destructor B"<<endl;
        }
};

int main(){
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();

    a->setB(b);
    b->setA(a);

    /*On running the above 4 lines of code, the shared pointers 'a' & 'b' points to 'A' & 'B' object on the heap
    respectively. The last 2 lines object A points to B and vice versa. Now, 'A' has use count of 1 in 'B'
    & 'B' has use count of 1 in 'A'. So, when 'a' goes out of scope it tries to destroy 'A' 
    but it notices that it has use count of 1 i.e., something else is referencing it and hence 
    it does not destroys it and the destructor never get called. Hence, 'a' & 'b' gets destoyed 
    which are on the stack but not the area on the heap which causes the memory leak. 
    This problem occurs due to implied shared ownership. The fix is can be done using a weak pointer.
    */

    shared_ptr<A> c = make_shared<A>();
    shared_ptr<B> d = make_shared<B>();

    c->setB(d);
    d->setA(c);

    return 0;
}