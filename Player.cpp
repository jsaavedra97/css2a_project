#include "Player.h"
using namespace std;

Player::Player() : Ship()
{
    projectiles->setSpeed(-1.0f);
}
Player::Player(string file_mid, int health, float x, float y, const Projectile& p  ) : Ship(file_mid, health, x, y, p)
{
    projectiles->setSpeed(-1.0f);
}
Player::Player(string file_left, string file_mid, string file_right,
               int health, float x, float y,const Projectile& p ) : Ship(file_left, file_mid, file_right, health, x, y, p)
{
    projectiles->setSpeed(-1.0f);
}
void Player::updateMovement(sf::RenderWindow& window)
{
    bool left = false,
         right = false;

    if(sprite.getGlobalBounds().top <= 0.0f)
        sprite.move(0.0f, 0.3f);
    else if(sprite.getGlobalBounds().top >= (window.getSize().y - sprite.getGlobalBounds().height))
        sprite.move(0.0f,-0.3f);
    else if(sprite.getGlobalBounds().left <= 0.0f)
        sprite.move(3.0f,0.0f);
    else if(sprite.getGlobalBounds().left >= (window.getSize().x - sprite.getGlobalBounds().width))
        sprite.move(-3.0f,0.0f);
    else
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            sprite.move(-0.3f, 0.0f);
            sprite.setTexture(texture_left);
            left = true;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            sprite.move(0.3f, 0.0f);
            sprite.setTexture(texture_right);
            right = true;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            sprite.move(0.0f, -0.3f);
            if(!left && !right)
                resetSprite();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            sprite.move(0.0f, 0.3f);
            if(!left && !right)
                resetSprite();
        }
        if(!left && !right)
            resetSprite();
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
            cout << "hello" << endl;

        }
    }
    for(int i = 0; static_cast<unsigned>(i) < weapon_load.size(); i++)
        window.draw(weapon_load[i].shape);

    for(int i = 0; static_cast<unsigned>(i) < weapon_load.size(); i++)
    {
        if(!weapon_load[i].update())
        {
            weapon_load.erase(weapon_load.begin());
            cout << "goodbye" << endl;

        }
    }
}
void Player::takeDamage(const Projectile &p)
{
    if(health - p.getDamage() > 0)
    {
        health -= p.getDamage();
    }
}
void Player::checkBounds()
{

}





