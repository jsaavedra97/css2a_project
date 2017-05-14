#include "ExternalEntity.h"
#include <iostream>
using namespace std;

ExternalEntity::ExternalEntity()
{
    is_dead = false;
    texture.loadFromFile("./sprites/no_image.png");
}
ExternalEntity::ExternalEntity(string img_path)
{
    is_dead = false;
    texture.loadFromFile(img_path);
    cout << "loaded" << endl;
//    texture.loadFromFile(img_path);
}
void ExternalEntity::setTexture(string img_path)
{
    texture.loadFromFile(img_path);
}
void ExternalEntity::setIsDead(bool is_dead)
{
    this->is_dead = is_dead;
}



