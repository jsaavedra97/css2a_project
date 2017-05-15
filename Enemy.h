#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "Projectile.h"
#include "Player.h"
using namespace std;

class Enemy : public Ship
{
public:
    Enemy();
    Enemy(string img_path, int health, const Projectile& p, const sf::Vector2f& start_pos, int movement_type, bool boss);
    void update(sf::RenderWindow& window);
    void fire(sf::RenderWindow& window, sf::Clock& clock, sf::Time& elapsed);
    void takeDamage(const Projectile *p);
    void checkIfHit(Ship *s);
    bool checkBounds( const sf::RectangleShape& r);
    bool checkBounds( const sf::Sprite& s);


private:
    int movement_type;
    // Used in checking movement
    bool boundary_checker;
};

#endif // ENEMY_H
