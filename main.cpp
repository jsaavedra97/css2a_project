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
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800,1000), "SPACE INVADERS");

    Environment e;
//    PowerUp p;

    
    sf::Clock clock2;
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
    return EXIT_SUCCESS;
}
