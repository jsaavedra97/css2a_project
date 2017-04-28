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
    Ship(string filename, int health,
         int num_weapons, float x, float y);
    ~Ship();

protected:
    string filename;
    int health,
        num_weapons;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::FloatRect boundingBox;
    Weapon *weapon;
};

#endif // SHIP_H
