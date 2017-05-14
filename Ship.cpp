#include "Ship.h"
#include "Environment.h"
#include <iostream>
using namespace std;

Ship::Ship():ExternalEntity()
{
    health = 0;
    texture.loadFromFile("./sprites/no_image.png");
    sprite.setTexture(texture);
    sprite.setOrigin(100.0f, 100.0f);
    projectiles = new Projectile;
}
Ship::Ship(string img_path, int health, const Projectile& p, sf::Vector2f start_pos, const Environment& e):ExternalEntity(img_path)
{
    assert(img_path != "");
    assert(health > 1);
    assert(start_pos.x > 0 && start_pos.y > 0 && start_pos.x < e.getWidth() && start_pos.y < e.getHeight());
    this->health = health;

    cout << sprite.getOrigin().x << " " << sprite.getOrigin().y << endl;
    cout << sprite.getPosition().x << " " << sprite.getPosition().y << endl;
    sprite.setOrigin(sprite.getLocalBounds().width/2, 0);
    sprite.setPosition(start_pos);

    cout << "*****" << endl;
    cout << sprite.getPosition().x << " " << sprite.getPosition().y << endl;
    cout << sprite.getOrigin().x << " " << sprite.getOrigin().y << endl;
    projectiles = new Projectile(p);
    projectiles->setPos(sprite.getOrigin());


}

