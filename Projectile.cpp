#include "Projectile.h"
using namespace std;

Projectile::Projectile(): Interactable()
{
}
Projectile::Projectile(const Projectile& p): Interactable()
{
    *this = p;
}
Projectile::Projectile(string img_path, int damage, float speed, int category):Interactable(img_path, damage, speed, category)
{
}
bool Projectile::update()
{
    if(shape.getPosition().y > 0)
    {
        shape.move(0.0f, speed);
        return true;
    }
    else
    {
        return false;
    }
}


