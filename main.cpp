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
    Environment *env = new Environment;

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
        // Clear screen

        sf::Time elapsed = clock.getElapsedTime();
        sf::Time elapsed2 = clock2.getElapsedTime();

        window.clear();

        //update
        player1->updateMovement(window);
        env->update();
        env->updatePowerUp(clock2, elapsed2);

//        if(player1->getSprite().getGlobalBounds().intersects(env->getPowerUp()->getShape().getGlobalBounds()))
//        {
//            player1->changeWeapon(env->getPowerUp()->getCategory());
//        }
        player1->checkBounds(env->getPowerUp());
        env->changePowerUp(player1->getSprite());
        // draw
        window.draw(env->getShape());
        window.draw(env->getPowerUp()->getShape());
        player1->fire(window, clock, elapsed);
        window.draw(player1->getSprite());
        window.display();
    }
    delete player1;
    delete env;
    return 0;
}
