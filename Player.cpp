#include "Player.h"

using namespace std;
string Player::file = "./sprites/player_sprites/smallfighter0005.png";
Player::Player() : Ship(Player::file, 100, 3, 400.0f, 500.0f)
{

}
Player::Player(string filename, int health, int num_weapons, float x,
               float y ) : Ship(filename, health, num_weapons, x, y)
{

}




