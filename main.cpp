#include <cassert>
#include "Player.h"
#include "Ship.h"
using namespace std;

int main()
{
    sf::Clock clock;
    int counter = 0;
    string file_left = "./sprites/player_sprites/smallfighter0001.png";
    string file_mid = "./sprites/player_sprites/smallfighter0005.png";
    string file_right = "./sprites/player_sprites/smallfighter0010.png";

    sf::RenderWindow window(sf::VideoMode(800, 1000), "SFML", sf::Style::Close | sf::Style::Titlebar);

    Ship *player1 = new Player(file_left, file_mid, file_right, 100, 400.0f, 800.0f);

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
        sf::Time elapsed = clock.getElapsedTime();

        window.clear();
//        cout << elapsed.asSeconds() << endl;
        player1->fire(window, clock, elapsed);
        player1->updateMovement();
        window.draw(player1->getSprite());
        window.display();
    }
    delete player1;

    return 0;
}
