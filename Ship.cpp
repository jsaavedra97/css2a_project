#include "Ship.h"

using namespace std;

Ship::Ship()
{
    health = 10;
    texture_mid.loadFromFile("./sprites/no_image.png");
    sprite.setTexture(texture_mid);
    sprite.setOrigin(100.0f, 100.0f);
    boundingBox = sprite.getGlobalBounds();
    projectiles = new Projectile;
}
Ship::Ship(string file_mid, int health, float x, float y,const Projectile& p)
{
    assert(health > 1);
    assert(file_mid != "");
    assert(x > 0 && y > 0); // need to assert upper-bounds

    this->health = health;
    texture_mid.loadFromFile(file_mid);
    sprite.setTexture(texture_mid);
    sprite.setPosition(x,y);
    sprite.setOrigin(sprite.getLocalBounds().width/2, 0);
    boundingBox = sprite.getGlobalBounds();
    projectiles = new Projectile(p);
}
Ship::Ship(string file_left, string file_mid, string file_right,
           int health, float x, float y,const Projectile& p)
{
    assert(health > 1);
    assert(file_mid != "");
    assert(x > 0 && y > 0); // need to assert upper-bounds

    this->health = health;
    texture_left.loadFromFile(file_left);
    texture_mid.loadFromFile(file_mid);
    texture_right.loadFromFile(file_right);
    sprite.setTexture(texture_mid);
    sprite.setPosition(x,y);
    sprite.setOrigin(sprite.getLocalBounds().width/2, 0);
    boundingBox = sprite.getGlobalBounds();
    projectiles = new Projectile(p);
}
void Ship::setPosition(float x, float y)
{
    assert(x > 0 && y > 0); // need to assert upper-bound
    sprite.setPosition(x,y);
}

void Ship::resetSprite()
{
    sprite.setTexture(texture_mid);
}
