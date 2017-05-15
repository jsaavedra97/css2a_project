#include "Player.h"
using namespace std;

Player::Player() : Ship()
{
    projectiles->setSpeed(-1.0f);
}
Player::Player(string img_path, int health, const Projectile& p, const sf::Vector2f& start_pos, const Environment& e) : Ship(img_path, health, p, start_pos)
{
    assert(start_pos.x > 0 && start_pos.y > 0 && start_pos.x < e.getWidth() && start_pos.y < e.getHeight());
    projectiles->setSpeed(-1.0f);
    texture_left.loadFromFile("./sprites/player_sprites/smallfighter0001.png");
    texture_right.loadFromFile("./sprites/player_sprites/smallfighter0010.png");
    cout<< "this runs" << endl;
    sprite.setPosition(sf::Vector2f(start_pos.x-sprite.getGlobalBounds().width/2, start_pos.y));
    sprite.setPosition(sf::Vector2f(sprite.getGlobalBounds().left-sprite.getGlobalBounds().width/2, sprite.getPosition().y));
    projectiles = new Projectile(p);
    projectiles->setPos(sprite.getPosition());
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
            sprite.setTexture(texture_left);
            left = true;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            sprite.move(0.4f, 0.0f);
            sprite.setTexture(texture_right);
            right = true;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            sprite.move(0.0f, -0.4f);
            left = false;
            right = false;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            sprite.move(0.0f, 0.4f);
            left = false;
            right = false;
        }
        if(!left && !right)
        {
            sprite.setTexture(texture);
        }
    }
}
void Player::fire(sf::RenderWindow& window, sf::Clock& clock, sf::Time& elapsed)
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if(elapsed.asSeconds() > 0.3)
        {
            weapon_load.push_back(new Projectile(*projectiles));
            weapon_load.back()->setPos(sf::Vector2f(sprite.getGlobalBounds().left+sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().top));
            clock.restart();
        }
    }
//    for(int i = 0; static_cast<unsigned>(i) < weapon_load.size(); i++)


    for(int i = 0; static_cast<unsigned>(i) < weapon_load.size(); i++)
    {
        window.draw(weapon_load[i]->shape);
        weapon_load[i]->update(window);


        if(weapon_load[i]->isDead())
        {
            delete weapon_load[i];
            weapon_load.erase(weapon_load.begin()+i);
        }
    }
}
void Player::takeDamage(const Projectile *p)
{
    if(health - p->getDamage() >= 0)
    {
        health -= p->getDamage();
    }
    else
        health = 0;
}
void Player::changeWeapon(const int& category)
{
    if(category == 0)
    {
        delete projectiles;
        projectiles = new Projectile("./sprites/laser.png", 50, -5.0f, 0, sf::Vector2f(20.0f,400.0f));
        cout << "changed 0" << endl;
    }
    else if(category == 1)
    {
        delete projectiles;
        projectiles = new Projectile("ll.png", 10, -5.0f, 1,sf::Vector2f(20.0f,100.0f));
        cout << "changed 1" << endl;
    }
}
bool Player::checkBounds(const sf::RectangleShape& r)
{
    if(sprite.getGlobalBounds().intersects(r.getGlobalBounds()))
    {
        return true;
    }
}
bool Player::checkBounds(const sf::Sprite& s)
{
    return (sprite.getGlobalBounds().intersects(s.getGlobalBounds()));
}
void Player::checkIfHit(Ship *s)
{
    for(int i = 0; i < weapon_load.size(); i++)
    {
        if(weapon_load[i]->checkBounds(s->getSprite()))
        {
            s->takeDamage(weapon_load[i]);
            weapon_load[i]->setIsDead(true);
        }
    }
}

//void Player::checkBounds(const PowerUp *p)
//{
//    if(sprite.getGlobalBounds().intersects(p->getShape().getGlobalBounds()))
//    {
//        changeWeapon(p->getCategory());
//    }
//}







