#include "Projectile.h"
using namespace std;

Projectile::Projectile(): Interactable()
{
}
Projectile::Projectile(const Projectile& p): Interactable()
{
    *this = p;
}
Projectile::Projectile(string *img_path_arr, int num_textures, int damage, float speed, int category):Interactable(img_path_arr, num_textures, damage, speed, category)
{
}
void Projectile::update(sf::RenderWindow& window)
{
    if(shape.getPosition().y > 0)
        shape.move(0.0f, speed);
    else
        is_dead = true;
}


