//***************************************
// Filename: Enemy.cpp
// Name: Joshua Saavedra
// Last Modified: 3/17/2017
// Description: This is the implementation
// file for the Enemy.h header
//***************************************
#include "Enemy.h"
#include <cassert>

Enemy::Enemy():
Ship("./sprites/enemy_sprites/asteroid.png", 25, 0, 0, Projectile()){
    enemy_name = "Asteroid";
    sprite.setRotation(180.0f);
    movement_type = 64; // Just an arbitrary number
    boundary_checker = true;
}

Enemy::Enemy(std::string file_name, int health, float x, float y, const Projectile& p, std::string enemy_name, int movement_type):
Ship(file_name, health, x, y, p){
    assert(!enemy_name.empty());
    assert(movement_type != 0);
    this->enemy_name = enemy_name;
    this->movement_type = movement_type;
    sprite.setRotation(180.0f);
    boundary_checker = true;
}

bool Enemy::enemyDeadOrAlive()const{
    if(health > 0)
        return false;
    return true;
}

void Enemy::fire(sf::RenderWindow& window, sf::Clock& clock, sf::Time& elapsed){
    if(elapsed.asSeconds() > 1.25f){
        clock.restart();
        projectiles->shape.setPosition(sprite.getPosition());
        weapon_load.push_back(*projectiles);
    }

    for(unsigned int i = 0; i < weapon_load.size(); i++)
        window.draw(weapon_load[i].shape);

    for(unsigned int i = 0; i < weapon_load.size(); i++)
        if(!weapon_load[i].update())
            weapon_load.erase(weapon_load.begin());
}

void Enemy::updateMovement(sf::RenderWindow& window){
    switch(movement_type){
    // Movement 1
    case 1:
        if(sprite.getPosition().x <= window.getSize().x - 65 && boundary_checker){
            sprite.move(0.05f, 0.0f);
            if(sprite.getPosition().x > window.getSize().x - 65)
                boundary_checker = false;
        }
        else if(sprite.getPosition().x >= window.getSize().x - 65 || (sprite.getPosition().x >= 65 && !boundary_checker)){
            sprite.move(-0.05f, 0.0f);
            if(sprite.getPosition().x < 65)
                boundary_checker = true;
        }

        if(sprite.getPosition().y < 1250)
            sprite.move(0.0f, 0.02f);
        break;

    // Movement 2
    case 2:
        if(sprite.getPosition().x >= 65 && boundary_checker){
            sprite.move(-0.05f, 0.0f);
            if(sprite.getPosition().x < 65)
                boundary_checker = false;
        }
        else if(sprite.getPosition().x <= 65 || (sprite.getPosition().x <= window.getSize().x - 65 && !boundary_checker)){
            sprite.move(0.05f, 0.0f);
            if(sprite.getPosition().x > window.getSize().x - 65)
                boundary_checker = true;
        }
        if(sprite.getPosition().y < 1250)
            sprite.move(0.0f, 0.02f);
        break;

    // Default Movement
    default:
        if(sprite.getPosition().y < 1250)
            sprite.move(0.0f, 0.05f);
        break;
    }
}

void Enemy::takeDamage(const Projectile& p){
    health -= p.getDamage();
    enemyDeadOrAlive();
}

void Enemy::checkBounds(){
    // Empty for now
}
