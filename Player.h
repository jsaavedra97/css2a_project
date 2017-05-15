#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "PowerUp.h"
#include "Enemy.h"

using namespace std;

class Player : public Ship
{
public:
    Player();
    Player(string img_path, int health, const Projectile& p, const sf::Vector2f& start_pos, const Environment& e);

    void update(sf::RenderWindow& window);
    void fire(sf::RenderWindow& window, sf::Clock& clock, sf::Time& elapsed,Ship *s);
    void takeDamage(const Projectile *p);
    bool checkBounds( const sf::RectangleShape& r);
    bool checkBounds( const sf::Sprite& s);
    void changeWeapon(const int& category);
//    void checkBounds(const PowerUp *p);

private:
    sf::Texture texture_left;
    sf::Texture texture_right;
};



#endif // PLAYER_H_INCLUDED
