//
//  Menu.cpp
//  bro
//
//  Created by Get Rekt M8 on 5/13/17.
//  Copyright © 2017 Get Rekt M8. All rights reserved.
//

#include "Menu.hpp"
using namespace std;
Menu::Menu(float width, float height)
{
    if(!font.loadFromFile("sansation.ttf"))
    {
        cout << "Error" << endl;
    }
    menu[0].setFont(font);
    menu[0].setCharacterSize(60);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2.30,height/(MAX_NUMBER_OF_ITEMS+1)*1));

    menu[1].setFont(font);
    menu[1].setCharacterSize(60);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Exit");
    menu[1].setPosition(sf::Vector2f(width/2.30,height/(MAX_NUMBER_OF_ITEMS+1)*2));

    selectItemIndex = 0;
}
Menu::~Menu()
{

}
void Menu::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}
void Menu::MoveUp()
{
    if(selectItemIndex - 1 >= 0)
    {
        menu[selectItemIndex].setFillColor(sf::Color::White);
        selectItemIndex--;
        menu[selectItemIndex].setFillColor(sf::Color::Red);
    }
}
void Menu::MoveDown()
{
    if(selectItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectItemIndex].setFillColor(sf::Color::White);
        selectItemIndex++;
        menu[selectItemIndex].setFillColor(sf::Color::Red);
    }
}
