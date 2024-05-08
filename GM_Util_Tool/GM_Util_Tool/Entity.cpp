#include "Entity.h"

Entity::Entity()
{

}

Entity::Entity(const std::string name, const int maxHealth, const int currentHealth,
	const int armor, const int evadePotential, const int attackPotential,
	const Weapon weapon, const bool alive, const bool magical)
{
	this->name = name;
	this->maxHealth = maxHealth;
	this->currentHealth = currentHealth;
	this->armor = armor;
	this->evadePotential = evadePotential;
	this->attackPotential = attackPotential;
	this->weapon = weapon;
	this->alive = alive;
	this->magical = magical;

}

Entity::Entity(const Entity&)
{

}


void Entity::takeDamage(int damage)
{
	currentHealth -= damage;
}


