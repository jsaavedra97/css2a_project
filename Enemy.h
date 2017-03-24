#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

//***************************************
// Header Name: Enemy.h
//***************************************
//***************************************
// Description: This class will create
// a basic enemy object for a game
//***************************************

#include <string>
#include <fstream>

class Enemy
{
    private:
        std::string enemy_name;
        int enemy_health;
        unsigned int enemy_power;

    public:
        //Constructors
        Enemy();
        Enemy(std::string enemy_name);
        Enemy(std::string enemy_name, int enemy_health);
        Enemy(std::string enemy_name, int enemy_health, unsigned int enemy_power);

        //Mutators
        void setEnemyName(std::string enemy_name){this->enemy_name = enemy_name;}
        //Summary: This method will set the Enemy's Name
        //Pre: Enemy only has the default name
        //Post: Enemy has a new name
        //***************************************
        //
        //***************************************
        void setEnemyHealth(int enemy_health){this->enemy_health = enemy_health;}
        //Summary: This method will set the Enemy Health
        //Pre: Enemy has no health
        //Post: Enemy has some health
        //***************************************
        //
        //***************************************
        void setEnemyPower(unsigned int enemy_power){this->enemy_power = enemy_power;}
        //Summary: This method will set the Enemy Power
        //Pre: Enemy has no power
        //Post: Enemy has some power
        //***************************************
        //
        //***************************************

        //Accessors
        std::string getEnemyName()const{return enemy_name;}
        //Summary:
        //Pre: Enemy's name is not return
        //Post: Enemy's name is returned
        //***************************************
        //
        //***************************************
        int getEnemyHealth()const{return enemy_health;}
        //Summary: This method will return the Enemy Health
        //Pre: Enemy health is not returned
        //Post: Enemy health is returned
        //***************************************
        //
        //***************************************
        unsigned int getEnemyPower()const{return enemy_power;}
        //Summary: This method will return the Enemy power
        //Pre: Enemy power is not returned
        //Post: Enemy power is returned
        //***************************************
        //
        //***************************************

        //Other Methods
        int enemyHealthAfterDamage(unsigned int damage_taken);
        //Summary: This method will change the enemy's health
        //Pre: Enemy health before taking damage
        //Post: Enemy health after taking damage
        //***************************************
        //
        //***************************************
        bool enemyDeadOrAlive()const;
        //Summary: This method will check to see if an enemy is dead or not
        //Pre: Not sure if the enemy is alive or not
        //Post: We know if the enemy is alive or not
        //***************************************
        //
        //***************************************

        //Overloaded Operator
        friend std::ostream& operator<<(std::ostream& os, const Enemy& e);
        //Summary: This friend function will print out the enemy info
        //Pre: Enemy information is not printed
        //Post: Enemy information is printed
        //***************************************
        //
};

#endif // ENEMY_H_INCLUDED
