//
//  Menu.cpp
//  bro
//
//  Created by Get Rekt M8 on 5/13/17.
//  Copyright © 2017 Get Rekt M8. All rights reserved.
//

#include "Menu.hpp"

Menu::Menu(float width, float hight)
{
   if(!font.loadFromFile(resourcePath() + "sansation.ttf"))
   {
       return cout << "Error" << endl;
   }
    menu[0].setFont(font);
    menu[0].setCharacterSize(60);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2.30,hight/(MAX_NUMBER_OF_ITEMS+1)*1));
    
    menu[1].setFont(font);
    menu[1].setCharacterSize(60);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Exit");
    menu[1].setPosition(sf::Vector2f(width/2.30,hight/(MAX_NUMBER_OF_ITEMS+1)*2));
    
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
        menu[selectItemIndex].setColor(sf::Color::White);
        selectItemIndex--;
        menu[selectItemIndex].setColor(sf::Color::Red);
    }
}
void Menu::MoveDown()
{
    if(selectItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectItemIndex].setColor(sf::Color::White);
        selectItemIndex++;
        menu[selectItemIndex].setColor(sf::Color::Red);
    }
}
