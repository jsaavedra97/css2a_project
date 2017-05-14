#ifndef SHIP_H
#define SHIP_H
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <cassert>
#include <iostream>
#include "Projectile.h"
#include "PowerUp.h"
#include "Environment.h"

using namespace std;

class Ship : public ExternalEntity
{
public:
    Ship();
    Ship(string img_path, int health, const Projectile& p, const sf::Vector2f& start_pos);
    virtual ~Ship(){}
    sf::Sprite getSprite()const{return sprite;}
    Projectile getProjectile(){return *projectiles;}

    virtual void update(sf::RenderWindow& window)=0;
    virtual void fire(sf::RenderWindow& window, sf::Clock& clock, sf::Time& elapsed)=0;
    virtual void takeDamage(const Projectile &p)=0;
    virtual bool checkBounds(const  sf::RectangleShape& r)=0;
    virtual bool checkBounds( const sf::Sprite& s)=0;


protected:
    int health;
    sf::Sprite sprite;
    Projectile *projectiles;
    vector<Projectile>weapon_load;
};

#endif // SHIP_H
