#include "ExternalEntity.h"
#include <iostream>
using namespace std;

ExternalEntity::ExternalEntity()
{
    num_textures = 0;
    is_dead = false;
    texture = new sf::Texture[num_textures];
    texture[0].loadFromFile("./sprites/no_image.png");
}
ExternalEntity::ExternalEntity(string *img_path_arr, int num_textures)
{
    is_dead = false;
    this->num_textures = num_textures;
    texture = new sf::Texture[num_textures];

    for(int i = 0; i < num_textures; i++)
        texture[i].loadFromFile(img_path_arr[i]);
//    texture.loadFromFile(img_path);
}
void ExternalEntity::setTexture(string *img_path_arr, int num_textures)
{
    this->num_textures = num_textures;
    texture = new sf::Texture[num_textures];
    for(int i = 0; i < num_textures; i++)
        texture[i].loadFromFile(img_path_arr[i]);
}
void ExternalEntity::setIsDead(bool is_dead)
{
    this->is_dead = is_dead;
}



