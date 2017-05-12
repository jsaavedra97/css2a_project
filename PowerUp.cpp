#include "PowerUp.hpp"

PowerUp::PowerUp():ExternalEntity()
{
    category = 1;
}
PowerUp::PowerUp(const sf::Vector2f& dim, const string&  file_name, int category):ExternalEntity(dim,file_name)
{
    this->category = category;
}
bool PowerUp::update()
{
    int x1, y1;
    x1 = rand()% (800 - 1)+ 1;
    y1 = rand()% (1000 - 1) +1;
    shape.setPosition(sf::Vector2f(x1, y1));
    return true;
}
