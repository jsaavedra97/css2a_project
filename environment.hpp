#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Environment
{
public:
        Environment();
        void Update(sf::RenderWindow &window, float elapsedTime);
        void Render(sf::RenderWindow &window);
       
private:
        sf::Texture bgTex;
        sf::Texture bg2Tex;

        sf::RectangleShape bgShape;
        sf::Vector2f bgSize;

        sf::Sprite      bgSprite;
        sf::Sprite      bg2Sprite;

        float bgSpeed;
        float bgY;
        float bg2Y;
        float windowbg1diff;
};
#endif
