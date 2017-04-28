#include "Ship.h"

using namespace std;

Ship::Ship()
{
    num_weapons = 3;
    health = 10;
    x_pos = 10;
    y_pos =10;
    hitbox_w = 10;
    hitbox_h = 10;
    weapon = new Weapon[num_weapons];
}
Ship::Ship(int health, int x_pos, int y_pos,
             int hitbox_h, int hitbox_w)
{
    num_weapons = 3;
    assert(num_weapons > 1 && num_weapons < 3);
    assert(health > 1);
    assert(x_pos > 0);
    assert(y_pos > 0);
    assert(hitbox_h > 0);
    assert(hitbox_w > 0);

    this->health = health;
    this->x_pos = x_pos;
    this->y_pos =y_pos;
    this->hitbox_w = hitbox_w;
    this->hitbox_h = hitbox_h;

    weapon = new Weapon[num_weapons];
}
Ship::Ship(int health, int x_pos, int y_pos,
           int hitbox_h, int hitbox_w, int num_weapons)
{
    assert(num_weapons > 1 && num_weapons < 3);
    assert(health > 1);
    assert(x_pos > 0);
    assert(y_pos > 0);
    assert(hitbox_h > 0);
    assert(hitbox_w > 0);
    this->num_weapons = num_weapons;
    this->health = health;
    this->x_pos = x_pos;
    this->y_pos =y_pos;
    this->hitbox_w = hitbox_w;
    this->hitbox_h = hitbox_h;

    weapon = new Weapon[num_weapons];
}
Ship::~Ship()
{
    delete[] weapon;
}
