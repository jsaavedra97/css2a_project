#include "Interactable.h"
using namespace std;

Interactable::Interactable(): ExternalEntity()
{
    damage = 5;
    speed = -5.0f;
    category = 1;
    shape.setSize(sf::Vector2f(20.0f, 20.0f));
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(10.0f, 0.0f);
    texture.loadFromFile("./sprites/no_image.png");
    shape.setTexture(&texture);
}
Interactable::Interactable(string img_path, int damage, float speed, int category, const sf::Vector2f shape_size):ExternalEntity(img_path)
{
    this->damage = damage;
    this->speed = speed;
    this->category = category;
    shape.setSize(shape_size);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(shape_size.x/2, 0.0f);
    shape.setTexture(&texture);
}
void Interactable::setPos(sf::Vector2f position)
{
    shape.setPosition(position);
}
void Interactable::setSize(sf::Vector2f s_size)
{
    shape.setSize(s_size);
}
void Interactable::setCategory(int category)
{
    this->category = category;
}
void Interactable::setSpeed(float speed)
{
    this->speed = speed;
}
bool Interactable::checkBounds( const sf::RectangleShape& r)
{
    return (shape.getGlobalBounds().intersects(r.getGlobalBounds()));
}
bool Interactable::checkBounds(const  sf::Sprite& s)
{
    return (shape.getGlobalBounds().intersects(s.getGlobalBounds()));
}
void Interactable::setTexture(string img_path)
{
    texture.loadFromFile(img_path);
    shape.setTexture(&texture);
}
