#include "PowerUp.h"

PowerUp::PowerUp():Interactable()
{
}
PowerUp::PowerUp(string img_path, int damage, float speed, int category):Interactable(img_path, damage, speed, category)
{
    shape.setSize(sf::Vector2f(20.0f, 20.0f));
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(10.0f, 0.0f);
    texture.loadFromFile(img_path);
    shape.setTexture(&texture);
}
void PowerUp::setSpawnTime(double spawn_time)
{
    this->spawn_time = spawn_time;
}
void PowerUp::update(sf::RenderWindow& window)
{

}

