#include "Enemy.h"
using namespace std;

Enemy::Enemy() : Ship()
{
    projectiles->setSpeed(1.0f);
    sprite.setRotation(180.0f);
    sprite.setScale(0.5f, 0.5f);
    movement_type = 64; // Just an arbitrary number
    boundary_checker = true;
}
Enemy::Enemy(string img_path, int health, const Projectile& p, const sf::Vector2f& start_pos, int movement_type, bool boss) : Ship(img_path, health, p, start_pos)
{
    assert(movement_type > 0);
    this->movement_type = movement_type;
    texture.loadFromFile(img_path);
    sprite.setTexture(texture);
    sprite.setRotation(180.0f);
    sprite.setPosition(sf::Vector2f(start_pos.x-sprite.getGlobalBounds().width/2, start_pos.y));
    if(!boss)
    {
        sprite.setScale(0.5f, 0.5f);
        projectiles->shape.setScale(0.5f, 0.5f);
    }
    else
        sprite.setScale(2.0f, 2.0f);

    projectiles->setSpeed(1.0f);
    movement_type = 64; // Just an arbitrary number
    boundary_checker = true;
}
void Enemy::update(sf::RenderWindow& window)
{
    switch(movement_type)
    {
    // Movement 1
    case 1:
        if(sprite.getPosition().x <= window.getSize().x - 35 && boundary_checker)
        {
            sprite.move(0.05f, 0.0f);
            if(sprite.getPosition().x > window.getSize().x - 35)
                boundary_checker = false;
        }
        else if(sprite.getPosition().x >= window.getSize().x - 35 || (sprite.getPosition().x >= 35 && !boundary_checker))
        {
            sprite.move(-0.05f, 0.0f);
            if(sprite.getPosition().x < 35)
                boundary_checker = true;
        }
        if(sprite.getPosition().y < 1100)
            sprite.move(0.0f, 0.02f);
        break;

    // Movement 2
    case 2:
        if(sprite.getPosition().x >= 35 && boundary_checker)
        {
            sprite.move(-0.05f, 0.0f);
            if(sprite.getPosition().x < 35)
                boundary_checker = false;
        }
        else if(sprite.getPosition().x <= 35 || (sprite.getPosition().x <= window.getSize().x - 35 && !boundary_checker))
        {
            sprite.move(0.05f, 0.0f);
            if(sprite.getPosition().x > window.getSize().x - 35)
                boundary_checker = true;
        }
        if(sprite.getPosition().y < 1100)
            sprite.move(0.0f, 0.02f);
        break;

    // Boss Movement
    case 99:
        if(sprite.getPosition().y < 300)
            sprite.move(0.0f, .02f);
        else if(sprite.getPosition().x >= 115 && boundary_checker)
        {
            sprite.move(-0.05f, 0.0f);
            if(sprite.getPosition().x < 115)
                boundary_checker = false;
        }
        else if(sprite.getPosition().x <= 115 || (sprite.getPosition().x <= window.getSize().x - 115 && !boundary_checker))
        {
            sprite.move(0.05f, 0.0f);
            if(sprite.getPosition().x > window.getSize().x - 115)
                boundary_checker = true;
        }
        break;
    // Default Movement
    default:
        if(sprite.getPosition().y < 1100)
            sprite.move(0.0f, 0.05f);
        break;
    }
}
void Enemy::fire(sf::RenderWindow& window, sf::Clock& clock, sf::Time& elapsed)
{


    if(elapsed.asSeconds() > 2)
    {
        clock.restart();

//        projectiles->setPos(sf::Vector2f(sprite.getGlobalBounds().left+sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().top));
        weapon_load.push_back(new Projectile(*projectiles));
        weapon_load.back()->setPos(sf::Vector2f(sprite.getGlobalBounds().left+sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().top));

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
void Enemy::takeDamage(const Projectile *p)
{
    cout << "health" << health << endl;
    if(health - p->getDamage() >= 0)
    {
        health -= p->getDamage();
    }
    else
        health = 0;
    cout << "health" << health << endl;
}
//void Enemy::changeWeapon(const int& category)
//{
//    if(category == 0)
//    {
//        delete projectiles;
//        projectiles = new Projectile("./sprites/player_sprites/smallfighter0005.png", 50, -5.0f, 0, sf::Vector2f(20.0f,100.0f));
//        cout << "changed 0" << endl;
//    }
//    else if(category == 1)
//    {
//        delete projectiles;
//        projectiles = new Projectile("ll.png", 10, -5.0f, 1,sf::Vector2f(20.0f,100.0f));
//        cout << "changed 1" << endl;
//    }
//}
bool Enemy::checkBounds(const sf::RectangleShape& r)
{
    if(sprite.getGlobalBounds().intersects(r.getGlobalBounds()))
    {
        return true;
    }
}
bool Enemy::checkBounds(const sf::Sprite& s)
{
    if(sprite.getGlobalBounds().intersects(s.getGlobalBounds()))
    {
        return true;
    }
}
void Enemy::checkIfHit(Ship *s)
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







