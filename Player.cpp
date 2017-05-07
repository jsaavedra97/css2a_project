#include "Player.h"
using namespace std;
string Player::file_left = "./sprites/player_sprites/smallfighter0001.png";
string Player::file_mid = "./sprites/player_sprites/smallfighter0005.png";
string Player::file_right = "./sprites/player_sprites/smallfighter0010.png";

Player::Player() : Ship(Player::getFileL(),Player::getFileM(),Player::getFileR(),
                            100, 400.0f, 700.0f)
{

}
Player::Player(string file_left, string file_mid, string file_right,
               int health, float x, float y ) : Ship(file_left, file_mid, file_right, health, x, y)
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
        sprite.setTexture(texture_left);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        sprite.move(0.2f, 0.0f);
        sprite.setTexture(texture_right);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        sprite.move(0.0f, -0.2f);
        sprite.setTexture(texture_mid);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sprite.move(0.0f, 0.2f);
        sprite.setTexture(texture_mid);
    }
    else
        sprite.setTexture(texture_mid);

}
void Player::fire(sf::RenderWindow& window, sf::Clock& clock, sf::Time& elapsed)
{
    if(elapsed.asSeconds() > 0.1)
    {
        clock.restart();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            projectiles->shape.setPosition(sprite.getPosition());
            weapon_load.push_back(*projectiles);
        }
    }
    for(int i = 0; i < weapon_load.size();i++)
        window.draw(weapon_load[i].shape);

    for(int i = 0; i < weapon_load.size();i++)
    {
        if(!weapon_load[i].update())
            weapon_load.erase(weapon_load.begin());
    }
}




