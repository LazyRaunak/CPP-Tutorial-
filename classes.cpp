/*
  -public - members are accessible from outside the class
  -private - members cannot be accessed (or viewed) from outside the class
  -protected - members cannot be accessed from outside the class, however, 
              they can be accessed in inherited classes.
  -By default, all members of a class have private access for all its members

  -Overriding replaces superclass functionality entirely using an identical method name and parameters and should be annotated.
  -Overloading is when you take an existing method and essentially define it again, but using different parameters.
  -Polymorphism is when you extend the base functionality of a superclass. You give some base functionality to the child classes and 
   then the child classes can develop their own behaviors.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
    public:
    string name;
    int health;
    int xp;

    void talk(string textToSay)
    {
        cout<<name<<" says "<<textToSay<<endl;
    }

    bool isDead();
};

int main()
{
    Player Frank;
    Player Pant;

    Player *enemy = new Player(); //creating object of Player class dynamically, on heap
    delete enemy;

    Player Pujara, Pane, Cook;

    Player Indian[] {Pant, Pujara}; //Indian is an array of Player object
    vector <Player> Aus {Pane}; //Vector of Player object 
    Aus.push_back(Cook);
    
    Frank.name = "frank";
    Frank.health = 100;
    Frank.xp = 12;
    Frank.talk("Fire in the hole!");

    (*enemy).name = "Enemy";
    enemy->health = 100;
    enemy->xp = 20;
    enemy->talk("Shoot 'em down");

    return 0;
}