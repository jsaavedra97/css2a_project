#include "Projectile.h"

Projectile::Projectile()
{
    damage = 5;
    speed = 1.0f;
    projectile = new sf::RectangleShape(sf::Vector2f(100.0f, 100.0f));
    projectile->setFillColor(sf::Color::White);
    projectile->setOrigin(50.0f, 50.0f);
    projectile->setPosition(400.0f, 800.0f);
    texture.loadFromFile("./sprites/player_sprites/smallfighter0005.png");
    projectile->setTexture(&texture);
    boundingBox = projectile->getGlobalBounds();

    name = "";
}
Projectile::Projectile(float x, float y, string name, string filename)
{
    damage = 5;
    speed = 1.0f;
    projectile = new sf::RectangleShape(sf::Vector2f(100.0f, 100.0f));
    projectile->setFillColor(sf::Color::White);
    projectile->setOrigin(50.0f, 50.0f);
    projectile->setPosition(x, y);
    texture.loadFromFile(filename);
    projectile->setTexture(&texture);
    boundingBox = projectile->getGlobalBounds();

    this->name = name;
}
Projectile::Projectile(float x, float y, float w, float h, string name, string filename, int damage)
{
    this->damage = damage;
    speed = 5;
    projectile = new sf::RectangleShape(sf::Vector2f(w, h));
    projectile->setFillColor(sf::Color::White);
    projectile->setOrigin(50.0f, 50.0f);
    projectile->setPosition(x, y);
    texture.loadFromFile(filename);
    projectile->setTexture(&texture);
    boundingBox = projectile->getGlobalBounds();

    this->name = name;
}
void Projectile::setDamage(int damage)
{
    assert(damage > 0);
    this->damage = damage;
}
void Projectile::setSpeed(int speed)
{
    assert(speed > 0);
    this->speed = speed;
}
void Projectile::setPosition(float x, float y)
{
    projectile->setPosition(x, y);
}
void Projectile::fire()
{

}
Projectile::~Projectile()
{
    delete projectile;
}


