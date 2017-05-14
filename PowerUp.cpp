#include "PowerUp.h"

PowerUp::PowerUp():Interactable()
{
}
PowerUp::PowerUp(string img_path, int damage, float speed, int category, const sf::Vector2f& shape_size):Interactable(img_path, damage, speed, category, shape_size)
{
}
void PowerUp::setSpawnTime(double spawn_time)
{
    this->spawn_time = spawn_time;
}
void PowerUp::update(sf::RenderWindow& window)
{

}

