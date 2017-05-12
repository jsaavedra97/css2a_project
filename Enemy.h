#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

//***************************************
// Header Name: Enemy.h
//***************************************
//***************************************
// Description: This class will create
// a basic enemy object for a game
//***************************************
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
//***************************************
#include "Ship.h"
#include "Projectile.h"

class Enemy : public Ship{
private:
    std::string enemy_name,
                file_name;

    // Might not be needed
    sf::Texture enemy_texture;
    sf::Sprite enemy_sprite;

    // Is important, don't touch!!
    int counter;

public:

    //Constructors
    Enemy();
    Enemy(std::string file_name, int health, float x, float y, const Projectile& p, std::string enemy_name);

    //Mutators
    void setEnemyName(std::string enemy_name){this->enemy_name = enemy_name;}
    //Accessors
    std::string getEnemyName()const{return enemy_name;}
    //Other Methods
    bool enemyDeadOrAlive()const;
    virtual void fire(sf::RenderWindow& window, sf::Clock& clock, sf::Time& elapsed);
    virtual void updateMovement(sf::RenderWindow& window);
    virtual void takeDamage(const Projectile &p);
    virtual void checkBounds();
};

#endif // ENEMY_H_INCLUDED