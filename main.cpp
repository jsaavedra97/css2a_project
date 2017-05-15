#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Menu.hpp"
#include "Environment.h"
#include "PowerUp.h"
#include "Player.h"
#include <vector>
#include "Enemy.h"

using namespace std;
sf::Vector2f gen_rand_spawn()
{
//    return sf::Vector2f(static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 7.0f)) * 100.0f, 10.0f);
    return sf::Vector2f(static_cast<float>(rand()%300+300), 10.0f);
}
int main()
{
    srand(time(NULL));

    sf::Clock player_clock;
    sf::Clock enemy_clock;
    sf::Clock powerup_clock;

    string file_path = "./sprites/enemy_sprites/";
    vector<string> ship_image;
    ship_image.push_back("./sprites/enemy_sprites/black_space_ship1.png");
    ship_image.push_back("./sprites/enemy_sprites/black_space_ship2.png");
    ship_image.push_back("./sprites/enemy_sprites/black_space_ship3.png");
    ship_image.push_back("./sprites/enemy_sprites/black_space_ship4.png");

    vector<Enemy*> enemy_ships;

    sf::Vector2f enemy_start_pos = sf::Vector2f(static_cast<float>(rand()%300+300), 10.0f);

    enemy_ships.push_back(new Enemy(ship_image[rand()%4], 100, Projectile(file_path + "alien_missile.png", 10, 0.05f, 1, sf::Vector2f(20.0f, 100.0f)), enemy_start_pos, 2, false));
    sf::Vector2f enemy_start_pos2 = sf::Vector2f(static_cast<float>(rand()%300+300), 10.0f);

    enemy_ships.push_back(new Enemy(ship_image[rand()%4], 100, Projectile(file_path + "alien_missile.png", 10, 0.05f, 1, sf::Vector2f(20.0f, 100.0f)), enemy_start_pos2, 2, false));
    sf::Vector2f enemy_start_pos3 = sf::Vector2f(static_cast<float>(rand()%300+300), 10.0f);

    enemy_ships.push_back(new Enemy(ship_image[rand()%4], 100, Projectile(file_path + "alien_missile.png", 10, 0.05f, 1, sf::Vector2f(20.0f, 100.0f)), enemy_start_pos3, 2, false));

    string file_mid = "./sprites/player_sprites/smallfighter0005.png";
    string file_left = "./sprites/player_sprites/smallfighter0001.png";
    string file_right = "./sprites/player_sprites/smallfighter0010.png";

    string textu = "./sprites/player_sprites/smallfighter0005.png";

    sf::RenderWindow window(sf::VideoMode(800, 1000), "Space Inviters", sf::Style::Close | sf::Style::Titlebar);

    Menu *menu = new Menu(window.getSize().x,window.getSize().y);

    Environment* env = new Environment;
    Player* player1 = new Player(file_mid,100,Projectile("./sprites/no_image.png", 10,-0.05f, 1, sf::Vector2f(20.0f,100.0f)), sf::Vector2f(400,800), *env);
//    Player* player1 = new Player(file_mid,100,Projectile("l.png", 10,-0.05f, 1, sf::Vector2f(20.0f,100.0f)), sf::Vector2f(400,800), *env);


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
            sf::Time p_projectile_elapse = player_clock.getElapsedTime(); // Player firing clock
            sf::Time e_projectile_elapse = enemy_clock.getElapsedTime(); // Enemy firing clock
            sf::Time powerup_elapse = powerup_clock.getElapsedTime(); // Environment powerup clock

            //update
            player1->update(window); // Player Movement

            for(int i = 0; static_cast<unsigned>(i) < enemy_ships.size(); i++) // Enemy Movement
            {
//                if(enemy_ships[i]->checkBounds(player1->getProjectile()->getShape()))
//                {
//                    cout <<" hit enemy check" << endl;
//                    enemy_ships[i]->takeDamage(player1->getProjectile());
//                }

                if(enemy_ships[i]->getPos().y >= 1100 || enemy_ships[i]->getHealth() <= 0)
                {
                    cout << "died" << endl;
                    delete enemy_ships[i];
                    enemy_ships.erase(enemy_ships.begin()+i);
                }
                else
                {
                    enemy_ships[i]->update(window);
                    window.draw(enemy_ships[i]->getSprite());
                }


            }

            env->update(window); // Environment Scroll



            if(env->getPowerUp())
            {
                if(player1->checkBounds(env->getPowerUp()->getShape())) // Touch PowerUp
                    player1->changeWeapon(env->getPowerUp()->getCategory());
            }
            env->changePowerUp(player1->getSprite(),powerup_clock,powerup_elapse, window); // Change PowerUp

            for(int i = 0; i < enemy_ships.size(); i++)
            {

            }

            // draw
            window.draw(env->getShape()); // Environment
            if(env->getPowerUp())
                window.draw(env->getPowerUp()->getShape()); // PowerUp
            for(int i = 0; static_cast<unsigned>(i) < enemy_ships.size(); i++)
            {
                player1->fire(window, player_clock, p_projectile_elapse, enemy_ships[i]); // Player Projectiles

                enemy_ships[i]->fire(window, enemy_clock, e_projectile_elapse, player1);
                window.draw(enemy_ships[0]->getSprite()); // Enemy
            }
            window.draw(player1->getSprite()); // Player

        }
        window.display();
    }
    delete player1;
    delete env;
    return 0;
}
