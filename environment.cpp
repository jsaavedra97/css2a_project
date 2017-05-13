#include "Environment.h"
#include <iostream>

using namespace std;
Environment::Environment():ExternalEntity()
{
    width = 800;
    height = 1000;
    scroll_speed = 0.3;
    elapsed_time = 0.7;

    texture.loadFromFile("./background.png");
    font.loadFromFile("./sansation.ttf");
    music.openFromFile("./spacenice.ogg");
    icon.loadFromFile("./shipIcon.png");
    texture.setSmooth(false);
    texture.setRepeated(true);

    y_pos = shape.getPosition().y;

    shape.setTexture(&texture);
    shape.setSize(sf::Vector2f(width, height));

    pu = new PowerUp;
    pu->setPos(genRandPos());

    music.play();

}
Environment::Environment(string img_path):ExternalEntity(img_path)
{
    width = 800;
    height = 1000;
    scroll_speed = 0.3;
    elapsed_time = 0.7;

    font.loadFromFile("./sansation.ttf");
    music.openFromFile("./spacenice.ogg");
    icon.loadFromFile("./shipIcon.png");
    texture.setSmooth(false);
    texture.setRepeated(true);

    y_pos = shape.getPosition().y;

    shape.setTexture(&texture);
    shape.setSize(sf::Vector2f(width, height));

    pu = new PowerUp;
    pu->setPos(genRandPos());

    music.play();

}
void Environment::update()
{
    if(y_pos <= 0.6 * height)
        y_pos -= scroll_speed * elapsed_time;
    else
        y_pos = shape.getPosition().y;
    shape.setTextureRect(sf::IntRect(0, y_pos, width, height));
}
void Environment::updatePowerUp(sf::Clock& clock2,sf::Time& elapsed2)
{
    int category;
    if (elapsed2.asSeconds() >= 10)
    {
        if(pu != NULL)
        {
            clock2.restart();

            category = rand()%2;
            delete pu;
            if(category == 1)
                pu = new PowerUp; // needs change
            else
                pu = new PowerUp; // needs change
            pu->setPos(sf::Vector2f(genRandPos()));
            cout << "update" << endl;
        }
    }
}
void Environment::changePowerUp(const sf::Sprite&s,sf::Clock& clock2,sf::Time& elapsed2 )
{
    if(pu->checkBounds(s))
    {
        int category = rand()%2;
        delete pu;

        clock2.restart();

        if(category == 1)
            pu = new PowerUp; // needs change
        else
            pu = new PowerUp;  // needs change
        pu->setCategory(category);
        pu->setPos(genRandPos());

    }
}
bool Environment::powerOff()
{
    if(pu == NULL)
        return true;
    return false;
}
sf::Vector2f Environment::genRandPos()
{
    int x,
        y;
    x = rand()% (width - 1) + 1;
    y = rand()% (height - 1) + 1;
    return sf::Vector2f(x,y);
}
