#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ResourcePath.hpp"
#include "Environment.hpp"
#include "PowerUp.hpp"

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800,1000), "SPACE INVADERS");

    Environment e;
    PowerUp p;
    
    sf::Clock Clock;
    sf::Time Time;
    
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

        // Clear screen
        window.clear();
        p.updatePowerUp(window,Clock,Time);
        e.Update(window, .7);
        p.renderPowerUp(window);
        e.Render(window);
        window.display();
    }
    return EXIT_SUCCESS;
}
