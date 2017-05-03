#ifndef SHIP_H
#define SHIP_H
#include <string>
#include <cassert>
#include <iostream>
#include "Weapon.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace std;

class Ship
{
public:
    Ship();
    Ship(string file_left, string file_mid, string file_right, int health,
         int num_weapons, float x, float y);
    sf::Sprite getSprite()const{return sprite;}
    sf::FloatRect getBoundingBox()const{return boundingBox;}
    Weapon getWeapon(int x)const{return weapon[x];}
    void setPosition(float x, float y);
    void resetSprite();
    ~Ship();

protected:
    string file_left,
           file_mid,
           file_right;
    int health,
        num_weapons;
    sf::Sprite sprite;
    sf::Texture texture_left;
    sf::Texture texture_mid;
    sf::Texture texture_right;
    sf::FloatRect boundingBox;
    Weapon *weapon;
};

#endif // SHIP_H
