#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Ship.h"

using namespace std;

class Player : public Ship
{
private:
    static string file_left;
    static string file_mid;
    static string file_right;
public:
    Player();
    Player(string file_mid, int health, float x, float y ,const Projectile& p );
    Player(string file_left, string file_mid, string file_right,
           int health, float x, float y,const Projectile& p);
    virtual ~Player(){}

    virtual void updateMovement(sf::RenderWindow& window);
    virtual void fire(sf::RenderWindow& window, sf::Clock& clock, sf::Time& elapsed);
    virtual void takeDamage(const Projectile &p);
    virtual void checkBounds(sf::RectangleShape &r);
    virtual void changeWeapon(int category);
};



#endif // PLAYER_H_INCLUDED
