#include "Projectile.h"
using namespace std;

Projectile::Projectile(): ExternalEntity()
{
    category = 1;
    damage = 5;
    speed = -5.0f;
}
Projectile::Projectile(const Projectile& p): ExternalEntity()
{
    *this = p;
}
Projectile::Projectile(int damage, float speed):ExternalEntity()
{
    this->damage = damage;
    this->speed = speed;
}
Projectile::Projectile(const sf::Vector2f& dim, string file_name, int damage, float speed):ExternalEntity(dim, file_name)
{
    this->damage = damage;
    this->speed = speed;
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
void Projectile::setType(int category)
{
    this->category = category;
    if(this->category == 1)
    {
        texture.loadFromFile("./sprites/player_sprites/smallfighter0005.png");
    }
    else if(this->category == 0);
    {
        texture.loadFromFile("./ll.png");

    }
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



