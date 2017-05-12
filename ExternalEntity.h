#ifndef EXTERNALENTITY_H
#define EXTERNALENTITY_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <cassert>
#include <iostream>

//sdfsdfs
class ExternalEntity
{
    public:
        ExternalEntity();
        virtual ~ExternalEntity(){}
        sf::RectangleShape getShape()const{return shape;}
        sf::FloatRect getBoundingBox()const{return boundingBox;}
        void setPosition(sf::Vector2f xy);
        virtual bool update()=0;


        sf::RectangleShape shape;
        sf::Texture texture;
        sf::FloatRect boundingBox;

};

#endif // EXTERNALENTITY_H
