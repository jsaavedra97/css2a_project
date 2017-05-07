#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cassert>
#include "Player.h"
#include "Projectile.h"
#include <deque>
#include <vector>
using namespace std;

void func()
{
    for(int i = 0; i < 10; i++)
        cout << "I'm thread number one" << endl;
}
int main()
{
//    Thread thread(&func);
//    thread.launch();
//
//
//
//    // run it
//    thread.launch();
//    for (int i = 0; i < 10; ++i)
//        cout << "I'm the main thread" << endl;

    int counter = 0;
    string file_left = "./sprites/player_sprites/smallfighter0001.png";
    string file_mid = "./sprites/player_sprites/smallfighter0005.png";
    string file_right = "./sprites/player_sprites/smallfighter0010.png";

    sf::RenderWindow window(sf::VideoMode(800, 1000), "SFML", sf::Style::Close | sf::Style::Titlebar);
    Player player1(file_left, file_mid, file_right, 100, 400.0f, 800.0f);
//    Projectile laser;
    deque<Projectile>weapon_box;
    vector<Projectile>::const_iterator iter;
    vector<Projectile>projectileArray;

//    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
//    player.setFillColor(sf::Color::White);
//    player.setOrigin(50.0f, 50.0f);
//    player.setPosition(400.0f, 800.0f);
//    sf::Texture playerTexture;
//    playerTexture.loadFromFile("./sprites/player_sprites/smallfighter0005.png");
//    player.setTexture(&playerTexture);

//
//    sf::Sprite sprite;
//
//    sf::Texture texture;
//
//    texture.loadFromFile(filename);
//    sprite.setTexture(texture);


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
        window.clear();

        player1.fire(window);

        player1.updateMovement();

        window.draw(player1.getSprite());
        window.display();
    }

    return 0;
}
