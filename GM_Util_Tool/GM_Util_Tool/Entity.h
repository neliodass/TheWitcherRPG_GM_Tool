#pragma once
#include <string>
#include "Weapon.h"
class Entity
{
	protected:
		std::string name;
		const int maxHealth;
		int currentHealth;
		int armor;
		int evadePotential;
		int attackPotential;
		Weapon weapon;
		bool alive = true;
		bool magical = false;

	public:
		void takeDamage(int damage);
		bool isAlive();
};

