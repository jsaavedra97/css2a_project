<<<<<<< HEAD
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
=======
#include <cassert>
#include "Player.h"
#include "Ship.h"
using namespace std;

int main()
{
    sf::Clock clock;
    string file_left = "./sprites/player_sprites/smallfighter0001.png";
    string file_mid = "./sprites/player_sprites/smallfighter0005.png";
    string file_right = "./sprites/player_sprites/smallfighter0010.png";

    sf::RenderWindow window(sf::VideoMode(800, 1000), "SFML", sf::Style::Close | sf::Style::Titlebar);

    Ship *player1 = new Player(file_left, file_mid, file_right, 100, 400.0f, 800.0f, Projectile());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
//            case sf::Event::TextEntered:
//                if(event.text.unicode < 128)
//                {
//                    printf("%c\n", event.text.unicode);
//                }
//                break;
            if(event.type==sf::Event::Closed)
            {
                window.close();
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
        }
        sf::Time elapsed = clock.getElapsedTime();
        window.clear();
        player1->fire(window, clock, elapsed);
        player1->updateMovement(window);
        window.draw(player1->getSprite());
        window.display();
    }
    delete player1;

    return 0;
>>>>>>> a55c28af8a69ebba7d67ec4552f818c367b03490
}
