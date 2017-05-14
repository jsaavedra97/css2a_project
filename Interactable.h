#ifndef INTERACTABLE_H
#define INTERACTABLE_H
#include "ExternalEntity.h"
#include <cassert>
#include <iostream>

using namespace std;

class Interactable:public ExternalEntity
{
    public:
        Interactable();
        Interactable(string img_path, int damage, float speed, int category);

        int getDamage()const{return damage;}
        int getSpeed()const{return speed;}

        void setDamage(int damage);
        void setSpeed(float speed);
        void setCategory(int category);


        virtual void update(sf::RenderWindow& window)=0;
        sf::Vector2f getPos()const{return shape.getPosition();}
        sf::Vector2f getSize()const{return shape.getSize();}
        sf::RectangleShape getShape()const{return shape;}
        void setPos(sf::Vector2f position);
        void setSize(sf::Vector2f s_size);
        bool checkBounds(const sf::RectangleShape& r);
        bool checkBounds(const sf::Sprite& s);
        void setTexture(string img_path);


        sf::RectangleShape shape;
        int damage;
        float speed;
        int category;

};

#endif // INTERACTABLE_H
