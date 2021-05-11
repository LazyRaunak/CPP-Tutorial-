#include <iostream>
#include <string>

using namespace std;

class Player{
    private:
        string name;
        string msg;
        int xp;
        int health;
        
    public:
        void set_name(string n)
        {
            name = n;
        }

        void talk(string m)
        {
            msg = m;
            cout<<"Player says: "<<msg<<endl;
        }

        Player(){
            cout<<"No args constructor called"<<endl;
        }

        Player(string name){
            cout<<"String args constructor called"<<endl;
        }

        Player(string name, int xp, int  health){
            cout <<"Three args constructor called"<<endl;
        }

        ~Player(){
            cout<<"Destructor called for name: "<<name<<endl;
        }
};

int main()
{
    Player slayer; //Default constructor since it doesn't expects any args
    slayer.set_name("Slayer");

    Player hero("Hero", 30, 99); /*Once we create a constructor for a class, C++ will not generate no args 
                                    default constructor automatically*/
    hero.set_name("Hero");

    Player cricket("Pant");
    cricket.set_name("Pant");

    Player *enemy = new Player;
    enemy->set_name("Enemy");
    (*enemy).talk("You're dead!");
    delete enemy;

    Player *boss = new Player("Boss", 55, 99);
    boss->set_name("Boss");
    delete boss;

    return 0;
}