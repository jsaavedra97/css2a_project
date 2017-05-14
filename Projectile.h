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
        Projectile(int damage, float speed);
        Projectile(const sf::Vector2f& dim, string file_name, int damage, float speed);
        virtual ~Projectile(){}

        int getDamage()const{return damage;}
        int getSpeed()const{return speed;}

        void setDamage(int damage);
        void setSpeed(float speed);

        bool update();

        int damage;
        float speed;
};

#endif // Projectile_H
