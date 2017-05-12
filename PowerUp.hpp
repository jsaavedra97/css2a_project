#ifndef PowerUp_hpp
#define PowerUp_hpp
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ResourcePath.hpp"
using namespace std;

class PowerUp
{
public:
    PowerUp();
    void updatePowerUp(sf::RenderWindow::RenderWindow &window, sf::Clock &Clock, sf::Time &Time);
    void renderPowerUp(sf::RenderWindow::RenderWindow &window);
private:
    sf::Texture powerUp;
    sf::Sprite powerUpSprite;
    sf::Texture powerUp2;
    sf::Sprite powerUpSprite2;
};

#endif /* PowerUp_hpp */
