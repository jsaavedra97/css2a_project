#ifndef POWERUP_H
#define POWERUP_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Interactable.h"
using namespace std;

class PowerUp: public Interactable
{
public:
    PowerUp();
    PowerUp(string img_path, int damage, float speed, int category,const sf::Vector2f& shape_size, float spawn_time);

    float getSpawnTime()const{return spawn_time;}
    void setSpawnTime(float spawn_time);
    void update(sf::RenderWindow& window);

public:
    float spawn_time;

};

#endif // POWERUP_H
