//***************************************
// Filename: Enemy.cpp
// Name: Joshua Saavedra
// Last Modified: 5/13/2017
// Description: This is the implementation
// file for the Enemy.h header
//***************************************
#include "Enemy.h"
#include <cassert>

Enemy::Enemy():
Ship("./sprites/enemy_sprites/asteroid.png", 25, Projectile(), sf::Vector2f(1, 1)){
    sprite.setRotation(180.0f);
    sprite.setScale(0.5f, 0.5f);
    movement_type = 64; // Just an arbitrary number
    boundary_checker = true;
}

Enemy::Enemy(string img_path, int health, const Projectile& p, const sf::Vector2f& start_pos, int movement_type, bool boss):
Ship(file_name, health, p, start_pos){
    assert(movement_type != 0);
    this->movement_type = movement_type;
    sprite.setRotation(180.0f);
    if(!boss){
        sprite.setScale(0.5f, 0.5f);
        projectiles->shape.setScale(0.5f, 0.5f);
    }
    else
        sprite.setScale(2.0f, 2.0f);
    boundary_checker = true;
}

void Enemy::fire(sf::RenderWindow& window, sf::Clock& clock, sf::Time& elapsed){
    if(elapsed.asSeconds() > 1.25f){
        clock.restart();
        projectiles->shape.setPosition(sprite.getPosition());
        weapon_load.push_back(*projectiles);
    }

    for(int i = 0; static_cast<unsigned>(i) < weapon_load.size(); i++)
        window.draw(weapon_load[i].shape);

    for(int i = 0; static_cast<unsigned>(i) < weapon_load.size(); i++){
        weapon_load[i].update(window);
        if(weapon_load[i].isDead())
            weapon_load.erase(weapon_load.begin());
            //cout << "hit" << endl;
    }
}

void Enemy::update(sf::RenderWindow& window){
    /*
    sf::Clock c;
    sf::Time e = c.getElapsedTime();

    fire(window, c, e);*/

    switch(movement_type){
    // Movement 1
    case 1:
        if(sprite.getPosition().x <= window.getSize().x - 35 && boundary_checker){
            sprite.move(0.05f, 0.0f);
            if(sprite.getPosition().x > window.getSize().x - 35)
                boundary_checker = false;
        }
        else if(sprite.getPosition().x >= window.getSize().x - 35 || (sprite.getPosition().x >= 35 && !boundary_checker)){
            sprite.move(-0.05f, 0.0f);
            if(sprite.getPosition().x < 35)
                boundary_checker = true;
        }
        if(sprite.getPosition().y < 1100)
            sprite.move(0.0f, 0.02f);
        break;

    // Movement 2
    case 2:
        if(sprite.getPosition().x >= 35 && boundary_checker){
            sprite.move(-0.05f, 0.0f);
            if(sprite.getPosition().x < 35)
                boundary_checker = false;
        }
        else if(sprite.getPosition().x <= 35 || (sprite.getPosition().x <= window.getSize().x - 35 && !boundary_checker)){
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
        else if(sprite.getPosition().x >= 115 && boundary_checker){
            sprite.move(-0.05f, 0.0f);
            if(sprite.getPosition().x < 115)
                boundary_checker = false;
        }
        else if(sprite.getPosition().x <= 115 || (sprite.getPosition().x <= window.getSize().x - 115 && !boundary_checker)){
            sprite.move(0.05f, 0.0f);
            if(sprite.getPosition().x > window.getSize().x - 115)
                boundary_checker = true;
        }
        break;

    // Default Movement
    default:
        if(sprite.getPosition().y < 1250)
            sprite.move(0.0f, 0.05f);
        break;
    }
}

// Not updated
bool Enemy::checkBounds(const sf::RectangleShape& r){
    return (sprite.getGlobalBounds().intersects(r.getGlobalBounds()));
}

bool Enemy::checkBounds(const sf::Sprite& s){
    return (sprite.getGlobalBounds().intersects(s.getGlobalBounds()));
}
