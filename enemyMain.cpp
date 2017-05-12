//***************************************
//
// Filename: enemyMain.cpp
// Name: Joshua Saavedra
// Last Modified: 5/2/17
// Description: This is the temporary driver for the
// Enemy class
//
//***************************************

#include "Enemy.h"
#include <ctime>
#include <cstdlib>

int main(){
    srand(static_cast<unsigned int>(time(NULL)));
    //srand(time(NULL));

    std::string file_path = "./sprites/enemy_sprites/";
    std::vector<std::string> ship_image = {"black_space_ship1.png", "black_space_ship2.png", "black_space_ship3.png"};

    //Ship *black_ship = new Enemy(file_path1, 100, 600.0f, 500.0f, "Black Ship");
    std::vector<Ship*> enemy_ships;
    enemy_ships.push_back(new Enemy(file_path + ship_image[rand()%3], 100, 600.0f, 300.0f, Projectile(10, 0.5f), "Enemy 1"));
    enemy_ships.push_back(new Enemy(file_path + ship_image[rand()%3], 100, 125.0f, 300.0f, Projectile(10, 0.5f), "Enemy 2"));
    ///enemy_ships.push_back(new Enemy(file_path + "boss_ship.png", 500, 200.0f, 200.0f, "Boss"));

    sf::RenderWindow window;
    sf::Clock clock;
    window.create(sf::VideoMode(800, 1000), "My Window!");

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    switch(event.key.code){
                        default: std::cout << "Something was pressed" << std::endl; break;
                    }
                    break;
                default:
                    break;
            }

        }
        sf::Time elapsed = clock.getElapsedTime();

        window.clear(sf::Color::Black);

        enemy_ships[0]->fire(window, clock, elapsed);
        enemy_ships[0]->updateMovement(window);
        window.draw(enemy_ships[0]->getSprite());

        enemy_ships[1]->fire(window, clock, elapsed);
        enemy_ships[1]->updateMovement(window);
        window.draw(enemy_ships[1]->getSprite());
        //if(enemy_ships[0]->getBoundingBox().contains(enemy_ships[1]->getBoundingBox()))
            //std::cout << "OH SHIT!" << std::endl;
        window.display();
    }

    //delete black_ship;
    for(int i = 0; i < enemy_ships.size(); i++)
        delete enemy_ships[i];
    return 0;
}
