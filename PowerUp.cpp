#include "PowerUp.h"

PowerUp::PowerUp():Interactable()
{
}
PowerUp::PowerUp(string img_path, int damage, float speed, int category):Interactable(img_path, damage, speed, category)
{
}
void PowerUp::setSpawnTime(double spawn_time)
{
    this->spawn_time = spawn_time;
}
