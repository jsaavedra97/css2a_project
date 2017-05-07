#ifndef SHIP_H
#define SHIP_H
#include <string>
#include <cassert>
#include <iostream>
#include "Projectile.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <deque>
using namespace std;

class Ship
{
public:
    Ship();
    Ship(string file_left, string file_mid, string file_right, int health, float x, float y);
    sf::Sprite getSprite()const{return sprite;}
    sf::FloatRect getBoundingBox()const{return boundingBox;}
    Projectile getProjectile(){return *projectiles;}
    void setPosition(float x, float y);
    void resetSprite();
    void fire();

protected:
    int health;
    sf::Sprite sprite;
    sf::Texture texture_left;
    sf::Texture texture_mid;
    sf::Texture texture_right;
    sf::FloatRect boundingBox;
    Projectile *projectiles;
    deque<Projectile>weapon_load;
};

#endif // SHIP_H
