#include "Player.h"
using namespace std;

Player::Player() : Ship()
{
}
Player::Player(string file_mid, int health, float x, float y ) : Ship(file_mid, health, x, y)
{

}
Player::Player(string file_left, string file_mid, string file_right,
               int health, float x, float y ) : Ship(file_left, file_mid, file_right, health, x, y)
{

}
void Player::updateMovement()
{
    bool left = false,
         right = false; //
    if((sprite.getGlobalBounds().top > 0.0f) && (sprite.getGlobalBounds().left > 0.0f))
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            sprite.move(-0.2f, 0.0f);
            sprite.setTexture(texture_left);
            left = true;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            sprite.move(0.2f, 0.0f);
            sprite.setTexture(texture_right);
            right = true;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            sprite.move(0.0f, -0.2f);
            if(!left && !right)
                sprite.setTexture(texture_mid);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            sprite.move(0.0f, 0.2f);
            if(!left && !right)
                sprite.setTexture(texture_mid);
        }
        if(!left && !right)
            sprite.setTexture(texture_mid);
    }
    else
    {
        sprite.move(0.0f,0.2f);
    }
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
    for(int i = 0; i < weapon_load.size(); i++)
        window.draw(weapon_load[i].shape);

    for(int i = 0; i < weapon_load.size(); i++)
    {
        if(!weapon_load[i].update())
            weapon_load.erase(weapon_load.begin());
    }
}




