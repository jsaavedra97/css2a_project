#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "PowerUp.h"

using namespace std;

class Environment
{
public:
    Environment();
    ~Environment();
    void update();
    void updatePowerUp(sf::Clock& clock2,sf::Time& elapsed2);

    sf::RectangleShape getPowerUp(){return p->getShape();}
    float getSpeed()const{return bgSpeed;}
    float getBgy()const{return bgY;}
    float getElapsedTime()const{return elapsedTime;}
    sf::RectangleShape getShape()const{return bgShape;}

private:
    sf::Texture bgTex;
    sf::RectangleShape bgShape;
    sf::Vector2f bgSize;
    sf::Font font;
    sf::Music music;
    sf::Image icon;
    float bgSpeed;
    float bgY;
    float elapsedTime;

    PowerUp *p;
};

#endif // ENVIRONMENT_H