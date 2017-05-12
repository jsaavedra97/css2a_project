#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ResourcePath.h"
#include "Environment.h"
#include "PowerUp.h"
#include "Player.h"

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
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
        }
        sf::Time elapsed2 = clock2.getElapsedTime();
        // Clear screen
        sf::Time elapsed = clock.getElapsedTime();

        window.clear();

        //update
        player1->fire(window, clock, elapsed);
        player1->updateMovement(window);
        e.Update(window, .7);
        e.powerUpTimer(window, clock2, elapsed2);


        // draw
        e.Render(window); // background
        window.draw(player1->getSprite()); // player
        window.draw(e.getPowerUp().getShape()); // powerup
        window.display();
    }
    return 0;
}
