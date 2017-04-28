#include "Ship.h"

using namespace std;

Ship::Ship()
{
    num_weapons = 3;
    health = 10;
    filename = "";
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    sprite.setOrigin(100.0f, 100.0f);
    boundingBox = sprite.getGlobalBounds();

    weapon = new Weapon[num_weapons];
}
Ship::Ship(string filename, int health, int num_weapons, float x, float y)
{
    assert(num_weapons > 1 && num_weapons < 3);
    assert(health > 1);
    num_weapons = 3;
    this->health = health;
    this->filename = filename;
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    sprite.setOrigin(x,y);
    boundingBox = sprite.getGlobalBounds();
    weapon = new Weapon[num_weapons];
}
Ship::~Ship()
{
    delete[] weapon;
}
