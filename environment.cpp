#include "environment.hpp"
Environment::Environment()
{
        bgSpeed = 0.3;

        bgTex.loadFromFile("background.jpg");
        bgTex.setSmooth(false);
        bgTex.setRepeated(true);

        bgY = bgShape.getPosition().y;
        bgSize.x = 800;
        bgSize.y = 600;

        bgShape.setTexture(&bgTex);
        bgShape.setSize(bgSize);
}

void Environment::Update(sf::RenderWindow &window, float elapsedTime)
{
        if (bgY < 600)
        {
               bgY -= bgSpeed * elapsedTime;
        }else
                {
                        bgY -= 0;
                }
        bgShape.setPosition(0, bgY);
}
void Environment::Render(sf::RenderWindow &window)
{
        window.draw(bgShape);
}
