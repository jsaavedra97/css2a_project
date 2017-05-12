#ifndef PowerUp_h
#define PowerUp_h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ExternalEntity.h"
using namespace std;

class PowerUp: public ExternalEntity
{
public:
    PowerUp();
    PowerUp(const sf::Vector2f& dim, const string&  file_name, int category);
    virtual bool update();
private:
    int category;
};

#endif /* PowerUp_hpp */
