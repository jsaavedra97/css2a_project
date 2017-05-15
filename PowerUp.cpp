#include "PowerUp.h"

PowerUp::PowerUp():Interactable()
{
    spawn_time = 5.0f;
}
PowerUp::PowerUp(string img_path, int damage, float speed, int category, const sf::Vector2f& shape_size, float spawn_time):Interactable(img_path, damage, speed, category, shape_size)
{
    assert(spawn_time > 0.0f);
    this->spawn_time = spawn_time;
}
void PowerUp::setSpawnTime(float spawn_time)
{
    this->spawn_time = spawn_time;
}
void PowerUp::update(sf::RenderWindow& window)
{

}

