#include "PowerUp.h"

PowerUp::PowerUp():ExternalEntity()
{
    category = 1;
}
PowerUp::PowerUp(const sf::Vector2f& dim, string file_name, int category):ExternalEntity(dim,file_name)
{
    this->category = category;
}
//bool PowerUp::checkBounds(sf::RectangleShape &r)
//{
//    if(shape.getGlobalBounds().intersects(r.getGlobalBounds()))
//    {
//    }
//}
//bool PowerUp::checkBounds(sf::Sprite &s)
//{
//    if(shape.getGlobalBounds().intersects(s.getGlobalBounds()))
//    {
//    }
//}
//
