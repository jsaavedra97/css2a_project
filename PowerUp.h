#ifndef POWERUP_H
#define POWERUP_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../ExternalEntity.h"
using namespace std;

class PowerUp: public ExternalEntity
{
public:
    PowerUp();
    PowerUp(const sf::Vector2f& dim, string file_name, int category);
    int getCategory()const{return category;}
private:
    int category;
};

#endif // POWERUP_H
