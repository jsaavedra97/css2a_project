#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Menu.hpp"
#include "Environment.h"
#include "PowerUp.h"
#include "Player.h"

using namespace std;
int main()
{

    sf::Clock player_clock;
    sf::Clock powerup_clock;

    string file_mid = "./sprites/player_sprites/smallfighter0005.png";
    string file_left = "./sprites/player_sprites/smallfighter0001.png";
    string file_right = "./sprites/player_sprites/smallfighter0010.png";

    string textu = "./sprites/player_sprites/smallfighter0005.png";

    sf::RenderWindow window(sf::VideoMode(800, 1000), "Space Inviters", sf::Style::Close | sf::Style::Titlebar);

    Menu *menu = new Menu(window.getSize().x,window.getSize().y);

    Environment* env = new Environment;
    Ship* player1 = new Player(file_mid,100,Projectile("l.png", 10,-0.1f, 1,sf::Vector2f(20.0f,100.0f)), sf::Vector2f(400,800), *env);

    srand(time(NULL));

    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            if(menu)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    menu->MoveUp();
                    break;
                case sf::Keyboard::Down:
                    menu->MoveDown();
                    break;
                case sf::Keyboard::Return:
                    switch (menu->getPressedItem())
                    {
                    case 0:
                        delete menu;
                        menu = NULL;
                        break;
                    case 1:
                        window.close();
                    }
                    break;
                }
            }
        }
        if(menu)
            menu->draw(window);
        else
        {
            sf::Time projectile_elapse = player_clock.getElapsedTime(); // Player firing clock
            sf::Time powerup_elapse = powerup_clock.getElapsedTime(); // Environment powerup clock
            //update
            player1->update(window);
            env->update(window);
            env->updatePowerUp(powerup_clock, powerup_elapse);
            player1->checkBounds(env->getPowerUp()->getShape());
            env->changePowerUp(player1->getSprite(),powerup_clock,powerup_elapse);
            // draw
            window.draw(env->getShape());
            window.draw(env->getPowerUp()->getShape());
            player1->fire(window, player_clock, projectile_elapse);
            window.draw(player1->getSprite());
        }
        window.display();
    }
    delete player1;
    delete env;
    return 0;
}
