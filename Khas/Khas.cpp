

#include <iostream>
#include <ctime>
#include "Khas.h"
using namespace std;

class badGuy {        // The class
public:          // Access specifier
    string name;
    int level = 1;
    int HP = 100;
    int MP = 50;
    int exp = 0;
    int AP = 0;
    int attackPower = 7; //Strength
    int defensePower = 3; //Defense
    int magicPower = 7;
    int magicDefense = 7;
    int speed = 7;
    int hitRate = 0;
    int accuracy = 72; 
    int magicAccuracy = 7;
    int evasion = 4;
    int agility = 7;
   
    /* int gethitRate(void) {
        srand((unsigned)time(NULL));
    // Retrieve a random number between 100 and 200
    // Offset = 100
    // Range = 101
        hitRate = accuracy + (rand() % 101);
        return hitRate;
    
    }
    oid attack(Guy badguy) {
        if (this->hitRate <= badguy.evasion)
            cout << "Attack Failed";
        else if (this->hitRate <= badguy.evasion)
            cout << "Attack Sucessful";
    }
    */
};
class goodGuy {        // The class
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

    /* int gethitRate(void) {
        srand((unsigned)time(NULL));
    // Retrieve a random number between 100 and 200
    // Offset = 100
    // Range = 101
        hitRate = accuracy + (rand() % 101);
        return hitRate;

    }
    oid attack(Guy badguy) {
        if (this->hitRate <= badguy.evasion)
            cout << "Attack Failed";
        else if (this->hitRate <= badguy.evasion)
            cout << "Attack Sucessful";
    }
    */
};
//ACT 1: Waking up on the island.

void oscarAttack()
{
   goodGuy Oscar;
   badGuy Joe;
   if (Joe.evasion < Oscar.accuracy && Oscar.attackPower > Joe.defensePower)
   {
       cout << "Oscar attacks: Direct hit!\n" << flush;
       system("CLS");
   }
   else {
       cout << "Oscar attacks: Attack Missed\n" << flush; 
       system("CLS");
   }

}
void joeAttack()
{
    goodGuy Oscar;
    badGuy Joe;
    if (Joe.accuracy > Oscar.evasion && Oscar.defensePower < Joe.attackPower)
    {
        cout << "Joe attacks: Direct hit!" << flush;
        system("CLS");
    }
    else {
        cout << "Joe attacks: Attack Missed" << flush;
        system("CLS");
    }

}
/*
void createBad()
{
    badGuy Joe;
}

void attack(badGuy, goodGuy) {
    if (badGuy::evasion > goodGuy::goodGuy::accuracy)
    {
        cout << "Direct Hit";
    }
}


*/
int main() {
   

    oscarAttack();
    joeAttack();





}


    







