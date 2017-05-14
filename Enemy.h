#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
//***************************************
// Header Name: Enemy.h
//***************************************
//***************************************
// Description: This class will create
// a basic enemy ship object
//***************************************
#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "Projectile.h"
using namespace std;

class Enemy: public Ship{
private:
    // Image name
    string file_name;
    // Determines Enemy movement pattern
    int movement_type;
    // Used in checking movement
    bool boundary_checker;

public:
    // Constructors
    Enemy();
    Enemy(string img_path, int health, const Projectile& p, const sf::Vector2f& start_pos, int movement_type, bool boss);

    // Virtual Methods
    virtual void fire(sf::RenderWindow& window, sf::Clock& clock, sf::Time& elapsed);
    virtual void update(sf::RenderWindow& window);
    virtual void takeDamage(const Projectile &p){health -= p.getDamage();}
    virtual bool checkBounds(const sf::RectangleShape& r);
    virtual bool checkBounds(const sf::Sprite& s);
};

#endif // ENEMY_H_INCLUDED
