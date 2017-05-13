#include "Environment.h"
#include <iostream>

using namespace std;
Environment::Environment()
{
    p = new PowerUp(sf::Vector2f(50.0f,50.0f),("l.png"), 1);
    int x1 = rand()% (800 - 1)+ 1;
    int y1 = rand()% (1000 - 1) +1;
    p->setPosition(sf::Vector2f(x1,y1));

    bgSpeed = 0.3;
    elapsedTime = 0.7;

    bgTex.loadFromFile("./background.png");
    font.loadFromFile("./sansation.ttf");
    music.openFromFile("./spacenice.ogg");
    icon.loadFromFile("./shipIcon.png");

    bgTex.setSmooth(false);
    bgTex.setRepeated(true);

    bgY = bgShape.getPosition().y;
    bgSize.x = 800;
    bgSize.y = 1000;

    bgShape.setTexture(&bgTex);
    bgShape.setSize(bgSize);
    music.play();
    cout << "test" << endl;

}
void Environment::update()
{
    if(bgY <= 600)
        bgY -= bgSpeed * elapsedTime;
    else
        bgY = bgShape.getPosition().y;
    bgShape.setTextureRect(sf::IntRect(0,bgY,800,1000));
}
void Environment::updatePowerUp(sf::Clock& clock2,sf::Time& elapsed2)
{
    int x1, y1, power_rand;
    if (elapsed2.asSeconds() >= 4)
    {
        if(p != NULL)
        {
            clock2.restart();
            x1 = rand()% (800 - 1)+ 1;
            y1 = rand()% (1000 - 1) +1;
            power_rand = rand()%2;
            delete p;
            if(power_rand == 1)
                p = new PowerUp(sf::Vector2f(50.0f,50.0f),("l.png"), power_rand);
            else
                p = new PowerUp(sf::Vector2f(50.0f,50.0f),("ll.png"), power_rand);
            p->setPosition(sf::Vector2f(x1, y1));
            cout << "update" << endl;
        }
    }
}
void Environment::changePowerUp(sf::Sprite s)
{
    if(p->checkBounds(s))
    {
        delete p;
        p = new PowerUp;
    }
}
Environment::~Environment()
{
    delete p;
}
