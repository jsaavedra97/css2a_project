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
        Projectile(string name, string filename);
        Projectile(float w, float h, string name,string filename, int damage);

        int getDamage()const{return damage;}
        int getSpeed()const{return speed;}

        sf::RectangleShape getShape()const{return shape;}
        sf::FloatRect getBoundingBox()const{return boundingBox;}

        void setDamage(int damage);
        void setSpeed(int speed);
        void setPosition(sf::Vector2f xy);

        bool update();

//    private:
        sf::RectangleShape shape;
        sf::Texture texture;
        sf::FloatRect boundingBox;

        int damage;
        float speed;
        string name;
};

#endif // Projectile_H
