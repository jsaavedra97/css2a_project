#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
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
    static string getFileL(){return Player::file_left;}
    static string getFileM(){return Player::file_mid;}
    static string getFileR(){return Player::file_right;}
//    void move_player(float x, float y);
    void updateMovement();



};



#endif // PLAYER_H_INCLUDED
