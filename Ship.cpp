#include "Ship.h"

using namespace std;

Ship::Ship()
{
    num_weapons = 1;
    health = 10;
    file_left = "./sprites/player_sprites/smallfighter0001.png";
    file_mid = "./sprites/player_sprites/smallfighter0005.png";
    file_right = "./sprites/player_sprites/smallfighter0010.png";
    texture_left.loadFromFile(file_left);
    texture_mid.loadFromFile(file_mid);
    texture_right.loadFromFile(file_right);
    sprite.setTexture(texture_mid);
    sprite.setOrigin(100.0f, 100.0f);
    boundingBox = sprite.getGlobalBounds();

    weapon = new Weapon[num_weapons];

}
Ship::Ship(string file_left, string file_mid, string file_right,
           int health, int num_weapons, float x, float y)
{
    assert(num_weapons >= 1 && num_weapons < 4);
    assert(health > 1);
    assert(x > 0 && y > 0);

    this->num_weapons = num_weapons;
    this->health = health;
    this->file_right = file_right;
    texture_left.loadFromFile(file_left);
    texture_mid.loadFromFile(file_mid);
    texture_right.loadFromFile(file_right);
    sprite.setTexture(texture_mid);
    sprite.setPosition(x,y);
    boundingBox = sprite.getGlobalBounds();
    weapon = new Weapon[num_weapons];
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
Ship::~Ship()
{
    delete[] weapon;
}
