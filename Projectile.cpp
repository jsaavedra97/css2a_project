#include "Projectile.h"
using namespace std;

Projectile::Projectile(): Interactable()
{
}
Projectile::Projectile(const Projectile& p): Interactable()
{
    *this = p;
}
Projectile::Projectile(string img_path,int damage, float speed, int category, const sf::Vector2f& shape_size):Interactable(img_path, damage, speed, category, shape_size)
{
}
void Projectile::update(sf::RenderWindow& window)
{
    if(shape.getPosition().y > 0)
    {
        shape.move(0.0f, speed);
//        cout << shape.getPosition().x << " " << shape.getPosition().y << endl;
    }
    else
        is_dead = true;
}


