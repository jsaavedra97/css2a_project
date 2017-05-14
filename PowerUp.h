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
    PowerUp(string img_path, int damage, float speed, int category);

    double getSpawnTime()const{return spawn_time;}
    void setSpawnTime(double spawn_time);
    void update(sf::RenderWindow& window);

private:
    double spawn_time;

};

#endif // POWERUP_H
