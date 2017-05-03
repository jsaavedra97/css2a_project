#include "Player.h"

using namespace std;
string Player::file = "./sprites/player_sprites/smallfighter0005.png";

Player::Player() : Ship(Player::getFile(), 100, 1, 400.0f, 700.0f)
{

}
Player::Player(string filename, int health, int num_weapons, float x,
               float y ) : Ship(filename, health, num_weapons, x, y)
{

}
//void Player::move_player(float x, float y)
//{
//    sprite.move(x, y);
//}
void Player::updateMovement()
{
//    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
//    {
//        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
//        player1.setPosition(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));
//    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        sprite.move(-0.2f, 0.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        sprite.move(0.2f, 0.0f);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        sprite.move(0.0f, -0.2f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sprite.move(0.0f, 0.2f);
    }
}





