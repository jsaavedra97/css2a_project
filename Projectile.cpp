#include "Projectile.h"


Projectile::Projectile()
{
    damage = 5;
    speed = -1.0f;
    shape.setSize(sf::Vector2f(20.0f, 100.0f));
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(10.0f, 0.0f);
    boundingBox = shape.getGlobalBounds();
    name = "";
}
Projectile::Projectile(float w, float h, string name, string filename, int damage)
{
    this->damage = damage;
    speed = -5.0f;
    shape.setSize(sf::Vector2f(w, h));
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(w/2, 0.0f);
    boundingBox = shape.getGlobalBounds();
    this->name = name;
}
void Projectile::setDamage(int damage)
{
    assert(damage > 0);
    this->damage = damage;
}
void Projectile::setSpeed(int speed)
{
    assert(speed < 0);
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



