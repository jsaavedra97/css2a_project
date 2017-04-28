#include "Weapon.h"

Weapon::Weapon()
{

}
Weapon::Weapon(int x_pos, int y_pos)
{
    damage = 5;
    speed = 5;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
}
Weapon::Weapon(int x_pos, int y_pos, string name)
{
    this->name = name;
    damage = 5;
    speed = 5;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
}
Weapon::Weapon(int x_pos, int y_pos, string name, int damage)
{
    this->name = name;
    this->damage = damage;
    speed = 5;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
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
void Weapon::setXPos(int x_pos)
{
    assert(x_pos > 0);
    this->x_pos = x_pos;
}
void Weapon::setYPos(int y_pos)
{
    assert(y_pos > 0);
    this->y_pos = y_pos;
}
void Weapon::setHitBoxH(int hitbox_h)
{
    assert(hitbox_h > 0);
    this->hitbox_h = hitbox_h;
}
void Weapon::setHitBixW(int hitbox_w)
{
    assert(hitbox_w > 0);
    this->hitbox_w = hitbox_w;
}

