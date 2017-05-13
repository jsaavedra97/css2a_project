#include "Projectile.h"
using namespace std;

Projectile::Projectile(): ExternalEntity()
{
    damage = 5;
    speed = -5.0f;
    category = 1;
}
Projectile::Projectile(const Projectile& p): ExternalEntity()
{
    *this = p;
}
Projectile::Projectile(string img_path, int damage, float speed, int category):ExternalEntity(img_path)
{
    this->damage = damage;
    this->speed = speed;
    this->category = category;
}
void Projectile::setDamage(int damage)
{
    assert(damage > 0);
    this->damage = damage;
}
void Projectile::setSpeed(float speed)
{
    this->speed = speed;
}
bool Projectile::update()
{
    if(shape.getPosition().y > 0)
    {
        shape.move(0.0f, speed);
        return true;
    }
    else
    {
        return false;
    }
}
void Projectile::setPos(sf::Vector2f position)
{
    shape.setPosition(position);
}
void Projectile::setSize(sf::Vector2f s_size)
{
    shape.setSize(s_size);
}
void Projectile::checkBounds(const sf::RectangleShape& r)
{

}
void Projectile::checkBounds(const sf::Sprite& s)
{

}



