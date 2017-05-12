#include "Environment.hpp"
Environment::Environment()
{
    p = new PowerUp(sf::Vector2f(50.0f,50.0f),("l.png"), 1);

    bgSpeed = 0.3;
    elapsedTime = 0.7;
    
    bgTex.loadFromFile(resourcePath() + "background.png");
    font.loadFromFile(resourcePath() + "sansation.ttf");
    music.openFromFile(resourcePath() + "spacenice.ogg");
    icon.loadFromFile(resourcePath() + "shipIcon.png");
    
    bgTex.setSmooth(false);
    bgTex.setRepeated(true);
    
    bgY = bgShape.getPosition().y;
    bgSize.x = 800;
    bgSize.y = 1000;
    
    bgShape.setTexture(&bgTex);
    bgShape.setSize(bgSize);
    music.play();
}

void Environment::Update(sf::RenderWindow &window, float elapsedTime)
{
    if(bgY <= 600)
        bgY -= bgSpeed * elapsedTime;
    else
        bgY = bgShape.getPosition().y;
    bgShape.setTextureRect(sf::IntRect(0,bgY,800,1000));
}
void Environment::Render(sf::RenderWindow &window)
{
    window.draw(bgShape);
}
void Environment::showPowerUp(sf::RenderWindow &window, sf::Clock &clock2,sf::Time &elapsed2)
{
    if (elapsed2.asSeconds() >= 2)
    {
        if(p->update())
        {
            cout << "update" << endl;
        }
        clock2.restart();
    }
}
