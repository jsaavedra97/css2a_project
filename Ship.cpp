#include "Ship.h"
#include "Environment.h"
#include <iostream>
using namespace std;

Ship::Ship():ExternalEntity()
{
    health = 0;
    texture.loadFromFile("./sprites/no_image.png");
    sprite.setTexture(texture);
    sprite.setOrigin(100.0f, 100.0f);
    projectiles = new Projectile;
}
Ship::Ship(string img_path, int health, const Projectile& p, const sf::Vector2f& start_pos):ExternalEntity(img_path)
{
    assert(img_path != "");
    assert(health > 1);
    this->health = health;
    sprite.setOrigin(sprite.getLocalBounds().width/2, 0);
    sprite.setPosition(sf::Vector2f(start_pos.x-sprite.getGlobalBounds().width/2, start_pos.y));
//    sprite.setPosition(sf::Vector2f(sprite.getGlobalBounds().left-sprite.getGlobalBounds().width/2, sprite.getPosition().y));
    projectiles = new Projectile(p);
    projectiles->setPos(sprite.getPosition());
}

