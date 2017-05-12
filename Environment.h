#ifndef Environment_h
#define Environment_h
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
    void Update(sf::RenderWindow &window, float elapsedTime);
    void Render(sf::RenderWindow &window);
    void powerUpTimer(sf::RenderWindow &window, sf::Clock& clock2,sf::Time& elapsed2);
    PowerUp getPowerUp(){return *p;}
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
#endif /* Environment_hpp */
