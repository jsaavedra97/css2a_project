#include "ExternalEntity.hpp"
#include "ResourcePath.hpp"
#include <iostream>
using namespace std;

ExternalEntity::ExternalEntity()
{
    shape.setSize(sf::Vector2f(20.0f, 20.0f));
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(10.0f, 0.0f);
    boundingBox = shape.getGlobalBounds();
}
ExternalEntity::ExternalEntity(const sf::Vector2f& dim, const string&  file_name)
{
    texture.loadFromFile(resourcePath()+file_name);

    shape.setSize(dim);
    shape.setFillColor(sf::Color::White);
    shape.setTexture(&texture);
    shape.setOrigin(dim.x/2, 0.0f);
    boundingBox = shape.getGlobalBounds();
}
void ExternalEntity::setPosition(sf::Vector2f xy)
{
    shape.setPosition(xy);
}


