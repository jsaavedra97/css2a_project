#ifndef Projectile_H
#define Projectile_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <string>
#include <cassert>
#include <iostream>

using namespace std;

class Projectile
{
    public:
        Projectile();
        Projectile(float x, float y, string name, string filename);
        Projectile(float x, float y, float w, float h, string name,string filename, int damage);
        ~Projectile();
        int getDamage()const{return damage;}
        int getSpeed()const{return speed;}
        sf::RectangleShape getPosition()const{return *projectile;}
        sf::FloatRect getBoundingBox()const{return boundingBox;}
        void setDamage(int damage);
        void setSpeed(int speed);
        void setPosition(float x, float y);
        void fire();


    private:
        sf::RectangleShape *projectile;
        sf::Texture texture;
        sf::FloatRect boundingBox;

        int damage;
        float speed;
        string name;
};

#endif // Projectile_H
