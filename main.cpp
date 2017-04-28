#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

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

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML", sf::Style::Close | sf::Style::Titlebar);
    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
    player.setFillColor(sf::Color::White);
    player.setOrigin(50.0f, 50.0f);
    sf::Texture playerTexture;
    playerTexture.loadFromFile("./player_sprite/smallfighter0005.png");
    player.setTexture(&playerTexture);
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
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            player.setPosition(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player.move(-0.1f, 0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.move(0.1f, 0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player.move(0.0f, -0.1f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player.move(0.0f, 0.1f);
        }


        window.clear(sf::Color::Black);
        window.draw(player);
        window.display();
    }

    return 0;
}
