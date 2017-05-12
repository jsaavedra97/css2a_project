#include "PowerUp.h"

PowerUp::PowerUp():ExternalEntity()
{
    category = 1;
}
PowerUp::PowerUp(const sf::Vector2f& dim, string file_name, int category):ExternalEntity(dim,file_name)
{
    this->category = category;
}

