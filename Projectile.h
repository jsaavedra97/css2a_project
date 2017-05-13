#ifndef Projectile_H
#define Projectile_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ExternalEntity.h"
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

class Projectile : public ExternalEntity
{
    public:
        Projectile();
        Projectile(const Projectile& p);
        Projectile(string img_path, int damage, float speed, int category);

        int getDamage()const{return damage;}
        int getSpeed()const{return speed;}
        void setDamage(int damage);
        void setSpeed(float speed);

        bool update();
        sf::Vector2f getPos()const{return shape.getPosition();}
        sf::Vector2f getSize()const{return shape.getSize();}
        void setPos(sf::Vector2f position);
        void setSize(sf::Vector2f s_size);
        void checkBounds(const sf::RectangleShape& r);
        void checkBounds(const sf::Sprite& s);
    private:
        sf::RectangleShape shape;
        int damage;
        float speed;
        int category;
};

#endif // Projectile_H
