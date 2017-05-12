#include "PowerUp.hpp"

PowerUp::PowerUp()
{
    powerUp.loadFromFile(resourcePath() + "l.png");
    powerUp2.loadFromFile(resourcePath() + "ll.png");
    
    powerUp.setSmooth(true);
    powerUpSprite.setTexture(powerUp);
    powerUpSprite.setScale(.023f, .023f);
    powerUp2.setSmooth(true);
    powerUpSprite2.setTexture(powerUp2);
    powerUpSprite2.setScale(.023f, .023f);
}
void PowerUp::updatePowerUp(sf::RenderWindow &window, sf::Clock &Clock, sf::Time &Time)
{
    srand(time(NULL));
    int x1;
    int y1;
    int x2;
    int y2;
    if (Time.asSeconds() >= 2)
    {
        x1 = rand()% (800 - 1)+ 1;
        y1 = rand()% (1000 - 1) +1;
        x2 = rand()% (800 - 1)+ 1;
        y2 = rand()% (1000 - 1)+ 1;
        powerUpSprite.setPosition(x1, y1);
        powerUpSprite2.setPosition(x2, y2);
        Clock.restart();
    }

}
void PowerUp::renderPowerUp(sf::RenderWindow &window)
{
    window.draw(powerUpSprite);
    window.draw(powerUpSprite2);
}
