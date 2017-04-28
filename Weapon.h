#ifndef WEAPON_H
#define WEAPON_H


#include <string>
#include <cassert>
#include <iostream>

using namespace std;

class Weapon
{
    public:
        Weapon();
        Weapon(int x_pos, int y_pos);
        Weapon(int x_pos, int y_pos, string name);
        Weapon(int x_pos, int y_pos, string name, int damage);

        int getDamage()const{return damage;}
        int getSpeed()const{return speed;}
        int getXPos()const{return x_pos;}
        int getYPos()const{return y_pos;}
        int getHitBoxH()const{return hitbox_h;}
        int getHitBoxW()const{return hitbox_w;}

        void setDamage(int damage);
        void setSpeed(int speed);
        void setXPos(int x_pos);
        void setYPos(int y_pos);
        void setHitBoxH(int hitbox_h);
        void setHitBixW(int hitbox_w);


    private:
        int damage,
            speed,
            x_pos,
            y_pos,
            hitbox_h,
            hitbox_w;
        string name;
};

#endif // WEAPON_H
