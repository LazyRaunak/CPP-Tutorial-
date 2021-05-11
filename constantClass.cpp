#include <iostream>
#include <string>

using namespace std;

class Player{
    private:
        string name;
        int xp;
        int health;
    public:
        void setName(string nameVal)
        {
            name = nameVal;
        }

        string getName () const
        {
            return name;
        }

        Player();
        // Player(string nameVal);
        Player(string nameVal, int xpVal, int healthVal);
};

Player::Player()
    :Player{"None", 0, 0}{
    }

// Player::Player(string nameVal)
//     :Player{nameVal, 0, 0}{
//     }

// Player::Player(string nameVal, int xpVal, int healthVal)
//     :Player{nameVal, xpVal, healthVal}{
//     }

Player::Player(string nameVal, int xpVal, int healtVal)
    :name{nameVal}, xp{xpVal}, health{healtVal}{
    }

int main()
{
    Player test;
    
    const Player kolhi{"Virat", 100, 50};
    kolhi.getName(); //while defining method the const keyword is added (at ln 17), else compiler throws
                     //an error that we are trying to modify a constant function.

    Player dhoni{"Mahi", 100, 50};

    return 0;
}