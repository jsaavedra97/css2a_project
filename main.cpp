#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ResourcePath.hpp"
#include "Environment.hpp"
#include "PowerUp.hpp"
using namespace std;
int main()
{

    sf::Clock clock;
	sf::Clock clock2;

    string file_left = "./sprites/player_sprites/smallfighter0001.png";
    string file_mid = "./sprites/player_sprites/smallfighter0005.png";
    string file_right = "./sprites/player_sprites/smallfighter0010.png";

    string textu = "./sprites/player_sprites/smallfighter0005.png";

    sf::RenderWindow window(sf::VideoMode(800, 1000), "Space Inviters", sf::Style::Close | sf::Style::Titlebar);

    Ship *player1 = new Player(file_left, file_mid, file_right, 100, 400.0f, 800.0f, Projectile(sf::Vector2f(20.0f,100.0f),textu,10,-1.0f));
	Environment e;

    srand(time(NULL));
    
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        sf::Time elapsed2 = clock2.getElapsedTime();
        // Clear screen

        window.clear();

        e.showPowerUp(window, clock2, elapsed2);
        e.Update(window, .7);
        e.Render(window);
        window.draw(e.getPowerUp().getShape());
        window.display();
    }
    return 0;
}
