#ifndef EXTERNALENTITY_H
#define EXTERNALENTITY_H
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;
//sdfsdfs
class ExternalEntity
{
    public:
        ExternalEntity();
        ExternalEntity(const sf::Vector2f& dim,const string&  file_name);
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
