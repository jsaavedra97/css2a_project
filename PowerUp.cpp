#include "PowerUp.h"

PowerUp::PowerUp():ExternalEntity()
{
    category = 1;
}
PowerUp::PowerUp(const sf::Vector2f& dim, string file_name, int category):ExternalEntity(dim,file_name)
{
    this->category = category;
}
void PowerUp::setCategory(int category)
{
    assert(category >=0 && category < 2);
    this->category = category;
}
void PowerUp::setDamage(int damage)
{
    assert(damage > 0);
    this->damage = damage;
}
void PowerUp::setSpeed(float speed)
{
    this->speed = speed;
}
