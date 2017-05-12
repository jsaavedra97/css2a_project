//***************************************
// Filename: enemyMain.cpp
// Name: Joshua Saavedra
// Last Modified: 5/2/17
// Description: This is the temporary driver for the
// Enemy class
//***************************************

#include "Enemy.h"
#include <ctime>
#include <cstdlib>

int main(){
    srand(static_cast<unsigned int>(time(NULL)));

    std::string file_path = "./sprites/enemy_sprites/";
    std::vector<std::string> ship_image = {"black_space_ship1.png", "black_space_ship2.png", "black_space_ship3.png"};

    std::vector<Ship*> enemy_ships;
    enemy_ships.push_back(new Enemy(file_path + ship_image[rand()%3], 100, 600.0f, 10.0f, Projectile(10, 0.5f), "Enemy 1", 2));
    enemy_ships.push_back(new Enemy(file_path + ship_image[rand()%3], 100, 125.0f, 10.0f, Projectile(10, 0.5f), "Enemy 2", 1));
    //enemy_ships.push_back(new Enemy(file_path + "boss_ship.png", 500, 200.0f, 800.0f, Projectile(50, 2.0f), "Boss"));

    sf::RenderWindow window;
    sf::Clock clock;
    window.create(sf::VideoMode(800, 1000), "My Window!");

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed: window.close(); break;
                case sf::Event::KeyPressed: switch(event.key.code){default: std::cout << "Something was pressed" << std::endl; break;} break;
                default: break;
            }
        }
        sf::Time elapsed = clock.getElapsedTime();

        window.clear(sf::Color::Black);

        // This loop does the enemy functionality
        for(unsigned int i = 0; i < enemy_ships.size(); i++){
            if(enemy_ships[i]->getSprite().getPosition().y < 1250){
                enemy_ships[i]->fire(window, clock, elapsed);
                enemy_ships[i]->updateMovement(window);
                window.draw(enemy_ships[i]->getSprite());
            }
            else{
                enemy_ships.erase(enemy_ships.begin() + i);
                if(rand() % 2 == 0)
                    enemy_ships.push_back(new Enemy(file_path + ship_image[rand()%3], 100, 600.0f, 10.0f, Projectile(10, 0.5f), "Enemy", rand() % 3 + 1));
                else
                    enemy_ships.push_back(new Enemy(file_path + ship_image[rand()%3], 100, 200.0f, 10.0f, Projectile(10, 0.5f), "Enemy", rand() % 3 + 1));
            }
        }
        /// This needs to be implemented
        //if(enemy_ships[0]->getBoundingBox().intersects(enemy_ships[1]->getBoundingBox()))
            //std::cout << "OH SHIT!" << std::endl;

        window.display();
    }

    // Deletes enemy_ships
    for(unsigned int i = 0; i < enemy_ships.size(); i++)
        delete enemy_ships[i];
    return 0;
}
