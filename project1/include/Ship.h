#ifndef SHIP_H
#define SHIP_H
#include <string>
#include <cassert>
#include <iostream>
#include <Weapon.h>

using namespace std;

class Ship
{
    public:
        Ship();
        Ship(int health, int x_pos, int y_pos,
             int hitbox_h, int hitbox_w);
        Ship(int health, int x_pos, int y_pos,
             int hitbox_h, int hitbox_w, int num_weapons);
        ~Ship();

    protected:
        int health,
            x_pos,
            y_pos,
            hitbox_w,
            hitbox_h,
            num_weapons;
        Weapon *weapon;
};

#endif // SHIP_H
