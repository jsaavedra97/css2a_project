//***************************************
//
// Filename: Enemy.cpp
// Name: Joshua Saavedra
// Last Modified: 3/17/2017
// Description: This is the implementation
// file for the Enemy.h header
//
//***************************************

#include "Enemy.h"
#include <cassert>

//Enemy::file_name = "./sprites/enemy_sprites/asteroid.png";

Enemy::Enemy():
Ship("./sprites/enemy_sprites/asteroid.png", 25, 0, 0, Projectile()){
    enemy_name = "Asteroid";
    sprite.setRotation(180.0f);
    counter = 0;
}

Enemy::Enemy(std::string file_name, int health, float x, float y, const Projectile& p, std::string enemy_name):
Ship(file_name, health, x, y, p){
    this->enemy_name = enemy_name;
    sprite.setRotation(180.0f);
    counter = 0;
}

bool Enemy::enemyDeadOrAlive()const{
    if(health > 0)
        return false;
    return true;
}

void Enemy::fire(sf::RenderWindow& window, sf::Clock& clock, sf::Time& elapsed){
    if(elapsed.asSeconds() > 1.25f)
    {
        clock.restart();
        projectiles->shape.setPosition(sprite.getPosition());
        weapon_load.push_back(*projectiles);
    }

    for(int i = 0; i < weapon_load.size(); i++)
        window.draw(weapon_load[i].shape);

    for(int i = 0; i < weapon_load.size(); i++)
    {
        if(!weapon_load[i].update())
            weapon_load.erase(weapon_load.begin());
    }
}

void Enemy::updateMovement(sf::RenderWindow& window){
    if(sprite.getPosition().x <= window.getSize().x - 65 && counter == 0){
        sprite.move(0.1f, 0.0f);
        if(sprite.getPosition().x > window.getSize().x - 65)
            counter = 1;
    }
    if(sprite.getPosition().x >= window.getSize().x - 65 || (sprite.getPosition().x >= 65 && counter == 1)){
        sprite.move(-0.1f, 0.0f);
        if(sprite.getPosition().x < 65)
            counter = 0;
    }
}

void Enemy::takeDamage(const Projectile& p){
    // Empty for now
}

void Enemy::checkBounds(){
    // Empty for now
}
