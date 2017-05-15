//***************************************
// Filename: enemyMain.cpp
// Name: Joshua Saavedra
// Last Modified: 5/13/17
// Description: This is the temporary driver for the
// Enemy class
//***************************************

#include "Enemy.h"
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;
int main(){
    srand(static_cast<unsigned>(time(NULL)));

    string file_path = "./sprites/enemy_sprites/";
    vector<string> ship_image;
    ship_image.push_back("black_space_ship1.png");
    ship_image.push_back("black_space_ship2.png");
    ship_image.push_back("black_space_ship3.png");
    ship_image.push_back("black_space_ship4.png");

    // Enemies
    vector<Ship*> enemy_ships;
    // Works with default constructor
    enemy_ships.push_back(new Enemy());

    /// Has issue with parameters
    enemy_ships.push_back(new Enemy(file_path + ship_image[rand()%4], 100, Projectile(file_path + "alien_missile.png", 10, 0.5f, 1, sf::Vector2f(20.0f, 100.0f)), sf::Vector2f(static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 7.0f)) * 100.0f, 10.0f), 2, false));
    enemy_ships.push_back(new Enemy(file_path + ship_image[rand()%4], 100, Projectile(file_path + "alien_missile.png", 10, 0.5f, 1, sf::Vector2f(20.0f, 100.0f)), sf::Vector2f(static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 7.0f)) * 100.0f, 10.0f), 1, false));
    // Boss prototype
    //Ship *boss_ship = new Enemy(file_path + "boss.png", 500, 400.0f, 10.0f, Projectile(50, 0.8f), 99, true);
    cout << "Hello World!" << std::endl;
    sf::RenderWindow window;
    sf::Clock clock;
    window.create(sf::VideoMode(800, 1000), "My Window!");

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed: window.close(); break;
                case sf::Event::KeyPressed: switch(event.key.code){default: cout << "Something was pressed" << endl; break;} break;
                default: break;
            }
        }
        sf::Time elapsed = clock.getElapsedTime();

        window.clear(sf::Color::Black);

        // Boss implementation Prototype
        //boss_ship->fire(window, clock, elapsed);
        //boss_ship->updateMovement(window);
        //window.draw(boss_ship->getSprite());

        // This loop does the enemy functionality
        for(unsigned int i = 0; i < enemy_ships.size(); i++){
            if(enemy_ships[i]->getSprite().getPosition().y < 1100){
                //enemy_ships[i]->fire(window, clock, elapsed);
                enemy_ships[i]->update(window);
                //enemy_ships[i]->checkBounds(*Player goes here*);
                window.draw(enemy_ships[i]->getSprite());
            }
            else{
                enemy_ships.erase(enemy_ships.begin() + i);
                // Calls Default
                enemy_ships.push_back(new Enemy());
                // Same issue here as before
                //enemy_ships.push_back(new Enemy(file_path + ship_image[rand()%4], 100, Projectile(file_path + "alien_missile.png", 10, 0.5f, 1, sf::Vector2f(20.0f, 100.0f)), sf::Vector2f(static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 7.0f)) * 100.0f, 10.0f), rand() % 3 + 1, false));
            }
        }
        window.display();
    }

    // Deletes enemy_ships
    for(unsigned int i = 0; i < enemy_ships.size(); i++)
        delete enemy_ships[i];
    //delete boss_ship;
    return 0;
}
