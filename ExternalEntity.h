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
        ExternalEntity(string *img_path_arr, int num_textures);
        virtual ~ExternalEntity(){}

        // Accessor
        sf::Vector2f getPos()const{}
        sf::Vector2f getSize()const{}
        int getNumTextures()const{return num_textures;}
        bool isDead()const{return is_dead;}
//        string getImgFile()const{return img_path;}

        //Mutator
        void setPos(sf::Vector2f position);
        void setSize(sf::Vector2f s_size);
        void setTexture(string* img_path_arr, int num_textures);
        void setNumTextures(int num_textures);
        void setIsDead(bool is_dead);

//        void setImgFile(string img_path);

        // Methods
        virtual void update(sf::RenderWindow& window)=0;
        virtual bool checkBounds(const sf::RectangleShape& r){}
        virtual bool checkBounds(const sf::Sprite& s){}


    protected:
        sf::Texture* texture;
        int num_textures;
        bool is_dead;
};

#endif // EXTERNALENTITY_H
