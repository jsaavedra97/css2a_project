#include "Ship.h"

using namespace std;

Ship::Ship()
{
    health = 10;

    texture_left.loadFromFile("./sprites/player_sprites/smallfighter0001.png");
    texture_mid.loadFromFile("./sprites/player_sprites/smallfighter0005.png");
    texture_right.loadFromFile("./sprites/player_sprites/smallfighter0010.png");
    sprite.setTexture(texture_mid);
    sprite.setOrigin(100.0f, 100.0f);
    boundingBox = sprite.getGlobalBounds();
//    projectiles = new Projectile;
}
Ship::Ship(string file_left, string file_mid, string file_right,
           int health, float x, float y)
{
    assert(health > 1);
    assert(x > 0 && y > 0);

    this->health = health;
    texture_left.loadFromFile(file_left);
    texture_mid.loadFromFile(file_mid);
    texture_right.loadFromFile(file_right);
    sprite.setTexture(texture_mid);
    sprite.setPosition(x,y);
    sprite.setOrigin(sprite.getLocalBounds().width/2, 0);
    boundingBox = sprite.getGlobalBounds();
    projectiles = new Projectile;
}
void Ship::setPosition(float x, float y)
{
    assert(x > 0 && y > 0);
    sprite.setPosition(x,y);
}
void Ship::resetSprite()
{
    sprite.setTexture(texture_mid);
}
