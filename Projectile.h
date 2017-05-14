#ifndef Projectile_H
#define Projectile_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Interactable.h"
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

class Projectile : public Interactable
{
    public:
        Projectile();
        Projectile(const Projectile& p);
        Projectile(string img_path, int damage, float speed, int category);
        void update(sf::RenderWindow& window);

    private:

};

#endif // Projectile_H
