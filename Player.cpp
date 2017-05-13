#include "Player.h"
using namespace std;

Player::Player() : Ship()
{
    projectiles->setSpeed(-1.0f);
}
Player::Player(string *img_path_arr, int num_textures, int health, Projectile& p, sf::Vector2f start_pos, Environment& e) : Ship(img_path_arr, num_textures, health, p, start_pos, e)
{
    projectiles->setSpeed(-1.0f);
}
void Player::update(sf::RenderWindow& window)
{
    bool left = false,
         right = false;

    if(sprite.getGlobalBounds().top <= 0.0f)
        sprite.move(0.0f, 0.4f);
    else if(sprite.getGlobalBounds().top >= (window.getSize().y - sprite.getGlobalBounds().height))
        sprite.move(0.0f,-0.4f);
    else if(sprite.getGlobalBounds().left <= 0.0f)
        sprite.move(4.0f,0.0f);
    else if(sprite.getGlobalBounds().left >= (window.getSize().x - sprite.getGlobalBounds().width))
        sprite.move(-4.0f,0.0f);
    else
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            sprite.move(-0.4f, 0.0f);
            sprite.setTexture(texture[0]);
            left = true;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            sprite.move(0.4f, 0.0f);
            sprite.setTexture(texture[2]);
            right = true;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            sprite.move(0.0f, -0.4f);
            if(!left && !right)
                sprite.setTexture(texture[1]);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            sprite.move(0.0f, 0.4f);
            if(!left && !right)
                sprite.setTexture(texture[1]);
        }
        if(!left && !right)
            sprite.setTexture(texture[1]);
    }
}
void Player::fire(sf::RenderWindow& window, sf::Clock& clock, sf::Time& elapsed)
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if(elapsed.asSeconds() > 0.5)
        {
            projectiles->setPos(sprite.getPosition());
            weapon_load.push_back(*projectiles);
            clock.restart();
        }
    }

    for(int i = 0; static_cast<unsigned>(i) < weapon_load.size(); i++)
        window.draw(weapon_load[i].getShape());

    for(int i = 0; static_cast<unsigned>(i) < weapon_load.size(); i++)
    {
        if(weapon_load[i].isDead())
            weapon_load.erase(weapon_load.begin());
    }
}
void Player::takeDamage(const Projectile &p)
{
    if(health - p.getDamage() > 0)
    {
        health -= p.getDamage();
    }
}
void Player::changeWeapon(const int& category)
{
//    if(category == 0)
//    {
//        delete projectiles;
//        projectiles = new Projectile(sf::Vector2f(20.0f,100.0f),"./sprites/player_sprites/smallfighter0005.png", 100, -5.0f);
//        cout << "changed" << endl;
//    }
//    else if(category == 1)
//    {
//        delete projectiles;
//        projectiles = new Projectile(sf::Vector2f(20.0f,100.0f),"ll.png", 10, -2.0f);
//        cout << "changed" << endl;
//    }
}
bool Player::checkBounds(const sf::RectangleShape& r)
{
    return (sprite.getGlobalBounds().intersects(r.getGlobalBounds()));
}
bool Player::checkBounds(const sf::Sprite& s)
{
    return (sprite.getGlobalBounds().intersects(s.getGlobalBounds()));
}






