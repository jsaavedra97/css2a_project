#include "Ship.h"
#include "Environment.h"
using namespace std;

Ship::Ship():ExternalEntity()
{
    health = 0;
    sprite.setTexture(texture[1]);
    projectiles = new Projectile;
}
Ship::Ship(string *img_path_arr, int num_textures, int health, Projectile& p, sf::Vector2f start_pos, Environment& e):ExternalEntity(img_path_arr, num_textures)
{
    for(int i = 0; i < num_textures; i++)
        assert(img_path_arr[i] != "");
    assert(health > 1);
    assert(start_pos.x > 0 && start_pos.y > 0 && start_pos.x < e.getWidth() && start_pos.y < e.getHeight());
    this->health = health;

    sprite.setPosition(start_pos);
    sprite.setOrigin(sprite.getLocalBounds().width/2, 0);
    projectiles = new Projectile(p);
}

