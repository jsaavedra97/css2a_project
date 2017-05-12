#include "Projectile.h"


Projectile::Projectile()
{
    damage = 5;
    speed = -5.0f;
    shape.setSize(sf::Vector2f(20.0f, 100.0f));
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(10.0f, 0.0f);
    boundingBox = shape.getGlobalBounds();
}
Projectile::Projectile(const Projectile& p)
{
    *this = p;
}
Projectile::Projectile(int damage, float speed)
{
    this->damage = damage;
    this->speed = speed;
    shape.setSize(sf::Vector2f(20.0f, 100.0f));
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(10.0f, 0.0f);
    boundingBox = shape.getGlobalBounds();
}
Projectile::Projectile(sf::Vector2f dim, int damage, float speed)
{
    this->damage = damage;
    this->speed = speed;
    shape.setSize(dim);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(dim.x/2, 0.0f);
    boundingBox = shape.getGlobalBounds();
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
void Projectile::setPosition(sf::Vector2f xy)
{
    shape.setPosition(xy);
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
        cout << "Collision" << endl;
        return false;
    }
}



