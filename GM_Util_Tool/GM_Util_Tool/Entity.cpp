#include "Entity.h"
void Entity::takeDamage(int damage)
{
	currentHealth -= damage;
}
bool Entity::isAlive()
{
	return alive;
}