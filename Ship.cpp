#include "Ship.h"

using namespace std;

Ship::Ship()
{
    num_weapons = 1;
    health = 10;
    filename = "./sprites/player_sprites/smallfighter0005.png";
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    sprite.setOrigin(100.0f, 100.0f);
    boundingBox = sprite.getGlobalBounds();

    weapon = new Weapon[num_weapons];

}
Ship::Ship(string filename, int health, int num_weapons, float x, float y)
{
    assert(num_weapons > 1 && num_weapons < 4);
    assert(health > 1);
    assert(x > 0 && y > 0);

    this->num_weapons = num_weapons;
    this->health = health;
    this->filename = filename;
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    sprite.setPosition(x,y);
    boundingBox = sprite.getGlobalBounds();
    weapon = new Weapon[num_weapons];
}
void Ship::setPosition(float x, float y)
{
    assert(x > 0 && y > 0);
    sprite.setPosition(x,y);
}
Ship::~Ship()
{
    delete[] weapon;
}
