#pragma once
#include <string>
class Entity
{
	protected:
		std::string name;
		const int maxHealth;
		int currentHealth;
		int armor;
		int evadePotential;
		int attackPotential;
		bool alive = true;
		bool magical = false;

	public:
		void takeDamage(int damage);
		bool isAlive();
};

