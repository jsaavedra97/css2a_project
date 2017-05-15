#include "Environment.h"
#include <iostream>
#include <typeinfo>
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

    pu = new PowerUp("l.png", 10, -0.05f, 1, sf::Vector2f(50.0f,50.0f), 10.0f);
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
    shape.setTexture(&texture);
    shape.setSize(sf::Vector2f(width, height));

    y_pos = shape.getPosition().y;
    pu = new PowerUp("l.png", 10, -0.05f, 1,sf::Vector2f(50.0f,50.0f), 10.0f);
    pu->setPos(genRandPos());

    music.play();

}
void Environment::update(sf::RenderWindow& window)
{
    if(y_pos <= 0.6 * height)
        y_pos -= scroll_speed * elapsed_time;
    else
        y_pos = shape.getPosition().y;
    shape.setTextureRect(sf::IntRect(0, y_pos, width, height));
}
//void Environment::updatePowerUp(sf::Clock& clock2,sf::Time& elapsed2)
//{
//    int category;
//    if (elapsed2.asSeconds() >= 2)
//    {
//        if(pu != NULL)
//        {
//            clock2.restart();
//            category = rand()%2;
//            delete pu;
//            if(category == 1)
//                pu = new PowerUp("ll.png",5, -0.05f, category,sf::Vector2f(50.0f,50.0f),  10.0f); // needs change
//            else
//                pu = new PowerUp("l.png", 10, -0.01, category,sf::Vector2f(50.0f,50.0f),  10.0f); // needs change
//            pu->setPos(sf::Vector2f(genRandPos()));
//            cout << "update" << endl;
//        }
//    }
//}
void Environment::changePowerUp(const sf::Sprite&s, sf::Clock& clock2,sf::Time& elapsed2, sf::RenderWindow& window )
{
    if(pu)
    {
        window.draw(pu->getShape());

        if(pu->checkBounds(s))
        {
            clock2.restart();
            delete pu;
            pu = NULL;
            cout << "touched" << endl;
        }
    }
    if (elapsed2.asSeconds() >= 10.0f)
    {
//        cout << typeid(elapsed2.asSeconds()).name() << endl;
        clock2.restart();
        if(pu)
        {
            delete pu;
            pu = NULL;
            cout << "Auto delete" << endl;
        }
        cout << "pre create" << endl;
        int category = rand()%2;
        if(category == 1)
            pu = new PowerUp("l.png",10, -0.05f, category,sf::Vector2f(50.0f,50.0f), 10.0f); // needs change
        else
            pu = new PowerUp("ll.png", 50, -0.01f, category,sf::Vector2f(50.0f,50.0f), 10.0f); // needs change
        pu->setPos(sf::Vector2f(genRandPos()));
        cout << "created" << endl;
    }
}
sf::Vector2f Environment::genRandPos()
{
    int x,
        y;
    x = rand()% (width - 1) + 1;
    y = rand()% (height - 1) + 1;
    return sf::Vector2f(x,y);
}
