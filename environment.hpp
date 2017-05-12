#ifndef Environment_hpp
#define Environment_hpp
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ResourcePath.hpp"
using namespace std;

class Environment
{
public:
    Environment();
    void Update(sf::RenderWindow::RenderWindow &window, float elapsedTime);
    void Render(sf::RenderWindow::RenderWindow &window);
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
};
#endif /* Environment_hpp */
