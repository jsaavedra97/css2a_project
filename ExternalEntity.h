#ifndef EXTERNALENTITY_H
#define EXTERNALENTITY_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

class ExternalEntity
{
    public:
        ExternalEntity();
        ExternalEntity(string img_path);
        virtual ~ExternalEntity(){}

        // Accessor
        virtual sf::Vector2f getPos()const=0;
        virtual sf::Vector2f getSize()const=0;
//        string getImgFile()const{return img_path;}

        //Mutator
        virtual void setPos(sf::Vector2f position)=0;
        virtual void setSize(sf::Vector2f s_size)=0;
        void setTexture(string img_file);
//        void setImgFile(string img_path);

        // Methods
        virtual void update()=0;
        virtual bool checkBounds(const sf::RectangleShape& r)=0;
        virtual bool checkBounds(const sf::Sprite& s)=0;

    protected:
//        string img_path;
        sf::Texture texture;
//        sf::Vector2f position;
//        sf::Vector2f dim;
};

#endif // EXTERNALENTITY_H
