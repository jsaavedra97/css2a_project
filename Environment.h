#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ExternalEntity.h"
#include "PowerUp.h"

using namespace std;

class Environment:public ExternalEntity
{
public:
    Environment();
    Environment(string img_path);
    void update();
    void updatePowerUp(sf::Clock& clock2,sf::Time& elapsed2);
    sf::Vector2f genRandPos();

    Interactable *getPowerUp(){return pu;}
    float getScrollSpeed()const{return scroll_speed;}
    float getYPos()const{return y_pos;}
    float getElapsedTime()const{return elapsed_time;}
    float getWidth()const{return width;}
    float getHeight()const{return height;}

    sf::RectangleShape getShape()const{return shape;}
    void changePowerUp(const sf::Sprite& s,sf::Clock& clock2,sf::Time& elapsed2);
    bool powerOff();

private:
    sf::RectangleShape shape;
    sf::Font font;
    sf::Music music;
    sf::Image icon;
    int width,
        height;
    float scroll_speed;
    float y_pos;
    float elapsed_time;

    Interactable *pu;
};

#endif // ENVIRONMENT_H
