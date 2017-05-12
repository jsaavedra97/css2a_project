#ifndef WEAPON_H
#define WEAPON_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <string>
#include <cassert>
#include <iostream>

using namespace std;

class Weapon
{
    public:
        Weapon();
        Weapon(float x, float y, string name, string filename);
        Weapon(float x, float y, float w, float h, string name,string filename, int damage);
        ~Weapon();
        int getDamage()const{return damage;}
        int getSpeed()const{return speed;}
        sf::RectangleShape getPosition()const{return *weapon;}
        sf::FloatRect getBoundingBox()const{return boundingBox;}
        void setDamage(int damage);
        void setSpeed(int speed);
        void setPosition(float x, float y);
        void fire();


    private:
        sf::RectangleShape *weapon;
        sf::Texture texture;
        sf::FloatRect boundingBox;

        int damage;
        float speed;
        string name,
               filename;
};

#endif // WEAPON_H
