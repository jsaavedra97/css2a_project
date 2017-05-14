#include "Projectile.h"
using namespace std;

Projectile::Projectile(): Interactable()
{
}
Projectile::Projectile(const Projectile& p): Interactable()
{
    *this = p;
}
Projectile::Projectile(string img_path,int damage, float speed, int category):Interactable(img_path, damage, speed, category)
{
    shape.setSize(sf::Vector2f(20.0f, 100.0f));
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(10.0f, 0.0f);
    texture.loadFromFile(img_path);
    shape.setTexture(&texture);
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


