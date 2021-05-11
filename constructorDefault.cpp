#include <iostream>
#include <string>

using namespace std;

class Player{
    private:
        string name;
        int xp;
        int health;
    
    public:
        void set_name(string nameVal)
        {
            name = nameVal;
        }

        string get_name()
        {
            return name;
        }

        Player(string nameVal, int xpVal, int healthVal)
        {
            name = nameVal;
            xp = xpVal;
            health = healthVal;
        }
};  

// Player::Player(string nameVal1, int xpVal1, int healthVal1)
//             :name{nameVal1}, xp{0}, health{0}{    
//                 cout<<"3 Args constructor"<<endl;            
//             }

int main()
{
    /*Player pant; If the default construcor is provided with 3 args, it'll throw error
                    for constructor with no args */
                    
    Player pant("Pant", 60, 100);
    pant.set_name("R. Pant");
    cout<<"Player name: "<<pant.get_name()<<endl;

    return 0;
}