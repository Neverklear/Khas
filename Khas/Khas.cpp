

#include <iostream>
#include <ctime>
using namespace std;

class Guy {        // The class
public:          // Access specifier
    string name;
    int level = 1;
    int HP = 100;
    int MP = 50;
    int exp = 0;
    int AP = 0;
    int attackPower = 7; //Strength
    int defensePower = 7; //Defense
    int magicPower = 7;
    int magicDefense = 7;
    int speed = 7;
    int hitRate = 0;
    int accuracy = 72; 
    int magicAccuracy = 7;
    int evasion = 7;
    int agility = 7;
   
    int gethitRate(void) {
        srand((unsigned)time(NULL));
    // Retrieve a random number between 100 and 200
    // Offset = 100
    // Range = 101
        hitRate = accuracy + (rand() % 101);
        return hitRate;
    
    }
    void attack(Guy badguy) {
        if (this->hitRate <= badguy.evasion)
            cout << "Attack Failed";
        else if (this->hitRate <= badguy.evasion)
            cout << "Attack Sucessful";
    }
};



    




int main()
{
    Guy Octavius;
    Guy Gremlin;
    Octavius.attack(Guy);
    Gremlin.attack();
      
};


