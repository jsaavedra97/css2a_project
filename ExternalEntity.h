#ifndef EXTERNALENTITY_H
#define EXTERNALENTITY_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;
//sdfsdfs
class ExternalEntity
{
    public:
        ExternalEntity();
        ExternalEntity(const sf::Vector2f& dim,string file_name);
        virtual ~ExternalEntity(){}
        sf::RectangleShape getShape()const{return shape;}
        sf::FloatRect getBoundingBox()const{return boundingBox;}
        void setPosition(const sf::Vector2f& xy);
        bool checkBounds(const sf::RectangleShape &r);
        bool checkBounds(const sf::Sprite &s);

        sf::RectangleShape shape;
        sf::Texture texture;
        sf::FloatRect boundingBox;

};

#endif // EXTERNALENTITY_H
