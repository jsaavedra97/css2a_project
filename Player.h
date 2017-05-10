#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
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
    Player(string file_left, string file_mid, string file_right,
           int health, float x, float y );
//    void move_player(float x, float y);
    void updateMovement();
    void fire(sf::RenderWindow& window, sf::Clock& clock, sf::Time& elapsed);
};



#endif // PLAYER_H_INCLUDED
