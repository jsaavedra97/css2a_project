#ifndef SHIP_H
#define SHIP_H
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <deque>
#include <vector>
#include <string>
#include <cassert>
#include <iostream>
#include "Projectile.h"

using namespace std;

class Ship
{
public:
    Ship();
    Ship(string file_mid, int health, float x, float y);
    Ship(string file_left, string file_mid, string file_right, int health, float x, float y);
    sf::Sprite getSprite()const{return sprite;}
    sf::FloatRect getBoundingBox()const{return boundingBox;}
    Projectile getProjectile(){return *projectiles;}
    void setPosition(float x, float y);
    void resetSprite();
    virtual void updateMovement(sf::RenderWindow& window)=0;
    virtual void fire(sf::RenderWindow& window, sf::Clock& clock, sf::Time& elapsed)=0;
    virtual ~Ship(){delete projectiles;}


protected:
    int health;
    sf::Sprite sprite;
    sf::Texture texture_left;
    sf::Texture texture_mid;
    sf::Texture texture_right;
    sf::FloatRect boundingBox;
    Projectile *projectiles;
    vector<Projectile>weapon_load;
};

#endif // SHIP_H
