#include "Entity.h"

Entity::Entity()
{

}

Entity::Entity(const Entity&)
{

}

void Entity::takeDamage(int damage)
{
	currentHealth -= damage;
}

