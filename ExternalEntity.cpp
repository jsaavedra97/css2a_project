#include "ExternalEntity.h"
#include <iostream>
using namespace std;

ExternalEntity::ExternalEntity()
{
    texture.loadFromFile("");
}
ExternalEntity::ExternalEntity(string img_path)
{
    texture.loadFromFile(img_path);
}
void ExternalEntity::setTexture(string img_path)
{
    texture.loadFromFile(img_path);
}



