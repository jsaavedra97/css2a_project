#include "Projectile.h"
using namespace std;

Projectile::Projectile(): Interactable()
{
    is_dead =false;

}
Projectile::Projectile(const Projectile& p): Interactable()
{
    *this = p;
    is_dead =false;

}
Projectile::Projectile(string img_path,int damage, float speed, int category, const sf::Vector2f& shape_size):Interactable(img_path, damage, speed, category, shape_size)
{
    is_dead =false;
}
void Projectile::update(sf::RenderWindow& window)
{
    if(shape.getPosition().y > 0)
    {
        shape.move(0.0f, speed);
    }
    else
    {
        cout << "hit end of screen" << endl;
        is_dead = true;
    }
}


