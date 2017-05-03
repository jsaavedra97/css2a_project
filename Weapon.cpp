#include "Weapon.h"

Weapon::Weapon()
{
    damage = 5;
    speed = 1.0f;
    weapon = new sf::RectangleShape(sf::Vector2f(100.0f, 100.0f));
    weapon->setFillColor(sf::Color::White);
    weapon->setOrigin(50.0f, 50.0f);
    weapon->setPosition(400.0f, 800.0f);
    texture.loadFromFile("./sprites/player_sprites/smallfighter0005.png");
    weapon->setTexture(&texture);
    boundingBox = weapon->getGlobalBounds();

    name = "";
}
Weapon::Weapon(float x, float y, string name, string filename)
{
    damage = 5;
    speed = 1.0f;
    weapon = new sf::RectangleShape(sf::Vector2f(100.0f, 100.0f));
    weapon->setFillColor(sf::Color::White);
    weapon->setOrigin(50.0f, 50.0f);
    weapon->setPosition(x, y);
    texture.loadFromFile(filename);
    weapon->setTexture(&texture);
    boundingBox = weapon->getGlobalBounds();

    this->name = name;
}
Weapon::Weapon(float x, float y, float w, float h, string name, string filename, int damage)
{
    this->damage = damage;
    speed = 5;
    weapon = new sf::RectangleShape(sf::Vector2f(w, h));
    weapon->setFillColor(sf::Color::White);
    weapon->setOrigin(50.0f, 50.0f);
    weapon->setPosition(x, y);
    texture.loadFromFile(filename);
    weapon->setTexture(&texture);
    boundingBox = weapon->getGlobalBounds();

    this->name = name;
}
void Weapon::setDamage(int damage)
{
    assert(damage > 0);
    this->damage = damage;
}
void Weapon::setSpeed(int speed)
{
    assert(speed > 0);
    this->speed = speed;
}
void Weapon::setPosition(float x, float y)
{
    weapon->setPosition(x, y);
}
void Weapon::fire()
{

}
Weapon::~Weapon()
{
    delete weapon;
}


