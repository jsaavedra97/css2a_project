#include "Interactable.h"
using namespace std;

Interactable::Interactable(): ExternalEntity()
{
    damage = 5;
    speed = -5.0f;
    category = 1;
}
Interactable::Interactable(string *img_path_arr, int num_textures, int damage, float speed, int category):ExternalEntity(img_path_arr, num_textures)
{
    this->damage = damage;
    this->speed = speed;
    this->category = category;
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
bool Interactable::checkBounds(const sf::RectangleShape& r)
{
    return (shape.getGlobalBounds().intersects(r.getGlobalBounds()));
}
bool Interactable::checkBounds(const sf::Sprite& s)
{
    return (shape.getGlobalBounds().intersects(s.getGlobalBounds()));
}
