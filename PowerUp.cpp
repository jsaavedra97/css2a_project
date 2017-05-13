#include "PowerUp.h"

PowerUp::PowerUp():Interactable()
{
}
PowerUp::PowerUp(string *img_path_arr, int num_textures, int damage, float speed, int category):Interactable(img_path_arr,num_textures, damage, speed, category)
{
}
void PowerUp::setSpawnTime(double spawn_time)
{
    this->spawn_time = spawn_time;
}
void PowerUp::update(sf::RenderWindow& window)
{

}

