#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Ship.h"

using namespace std;

class Player : public Ship
{
public:
    Player();
    Player(string *img_path_arr, int num_textures, int health, Projectile& p, sf::Vector2f start_pos, Environment& e);

    void update(sf::RenderWindow& window);
    void fire(sf::RenderWindow& window, sf::Clock& clock, sf::Time& elapsed);
    void takeDamage(const Projectile &p);
    bool checkBounds(const sf::RectangleShape& r);
    bool checkBounds(const sf::Sprite& s);
    void changeWeapon(const int& category);
};



#endif // PLAYER_H_INCLUDED
