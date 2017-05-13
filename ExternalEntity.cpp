#include "ExternalEntity.h"
#include <iostream>
using namespace std;

ExternalEntity::ExternalEntity()
{
    shape.setSize(sf::Vector2f(20.0f, 20.0f));
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(10.0f, 0.0f);
    boundingBox = shape.getGlobalBounds();
}
ExternalEntity::ExternalEntity(const sf::Vector2f& dim, string file_name)
{
    texture.loadFromFile(file_name);
    shape.setSize(dim);
    shape.setFillColor(sf::Color::White);
    shape.setTexture(&texture);
    shape.setOrigin(dim.x/2, 0.0f);
    boundingBox = shape.getGlobalBounds();
}
void ExternalEntity::setPosition(const sf::Vector2f& xy)
{
    shape.setPosition(xy);

}
bool ExternalEntity::checkBounds(const sf::RectangleShape &r)
{
    if(shape.getGlobalBounds().intersects(r.getGlobalBounds()))
    {
        return true;
    }
    return false;
}
bool ExternalEntity::checkBounds(const sf::Sprite &s)
{
    if(shape.getGlobalBounds().intersects(s.getGlobalBounds()))
    {
        return true;
    }
    return false;
}



