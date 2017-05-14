//
//  Menu.hpp
//  bro
//
//  Created by Get Rekt M8 on 5/13/17.
//  Copyright © 2017 Get Rekt M8. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>

#define MAX_NUMBER_OF_ITEMS 2
using namespace std;

class Menu
{
public:
    Menu(float width, float height);
    ~Menu();
    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int getPressedItem()const{return selectItemIndex;}
private:
    int selectItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
};

#endif /* Menu_hpp */
