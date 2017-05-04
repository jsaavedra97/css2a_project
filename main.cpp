#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cassert>
#include "Player.h"
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
    string file_left = "./sprites/player_sprites/smallfighter0001.png";
    string file_mid = "./sprites/player_sprites/smallfighter0005.png";
    string file_right = "./sprites/player_sprites/smallfighter0010.png";

    sf::RenderWindow window(sf::VideoMode(800, 1000), "SFML", sf::Style::Close | sf::Style::Titlebar);
    Player player1(file_left, file_mid, file_right, 100, 400.0f, 800.0f);

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
            switch(event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::TextEntered:
                if(event.text.unicode < 128)
                {
                    printf("%c\n", event.text.unicode);
                }

                break;
            }

        }
//        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
//        {
//            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
////            player.setPosition(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));
//            player1.setPosition(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));
//        }
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//        {
////            player.move(-0.2f, 0.0f);
//            player1.move_player(-0.2f, 0.0f);
//        }
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//        {
////            player.move(0.2f, 0.0f);
//            player1.move_player(0.2f, 0.0f);
//
//        }
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//        {
////            player.move(0.0f, -0.2f);
//            player1.move_player(0.0f, -0.2f);
//        }
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//        {
////            player.move(0.0f, 0.2f);
//            player1.move_player(0.0f, 0.2f);
//        }
        player1.updateMovement();
//        player1.resetSprite();


        window.clear(sf::Color::Black);
//        window.draw(player);
        window.draw(player1.getSprite());
        window.display();
    }

    return 0;
}
