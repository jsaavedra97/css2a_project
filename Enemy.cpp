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

Enemy::Enemy()
{
    enemy_name = "Cockroach";
    enemy_health = 1;
    enemy_power = 1;
}

Enemy::Enemy(std::string enemy_name)
{
    this->enemy_name = enemy_name;
    enemy_health = 1;
    enemy_power = 1;
}

Enemy::Enemy(std::string enemy_name, int enemy_health)
{
    this->enemy_name = enemy_name;
    this->enemy_health = enemy_health;
    enemy_power = 1;
}

Enemy::Enemy(std::string enemy_name, int enemy_health, unsigned int enemy_power)
{
    this->enemy_name = enemy_name;
    this->enemy_health = enemy_health;
    this->enemy_power = enemy_power;
}

int Enemy::enemyHealthAfterDamage(unsigned int damage_taken)
{
    enemy_health -= damage_taken;
    return enemy_health;
}

bool Enemy::enemyDeadOrAlive()const
{
    if(enemy_health < 0)
        return false;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Enemy& e)
{
    os << "Enemy Name: " << e.getEnemyName() << std::endl
       << "Current Health: " << e.getEnemyHealth() << std::endl
       << "Power Level: " << e.getEnemyPower() << std::endl
       << "Status: " << (e.enemyDeadOrAlive() ? "Alive" : "Deceased")
       << std::endl;

    return os;
}
