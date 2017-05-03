#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Ship.h"
using namespace std;

class Player : public Ship
{
private:
    static string file;
public:
    Player();
    Player(string filename, int health, int num_weapons, float x,
           float y );
    static string getFile(){return Player::file;}
    void move_player(float x, float y);


};



#endif // PLAYER_H_INCLUDED
