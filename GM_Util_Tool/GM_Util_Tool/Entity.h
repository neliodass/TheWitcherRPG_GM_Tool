#pragma once
#include <string>
#include "Weapon.h"
class Entity
{
	protected:
		std::string name = "";
		int maxHealth = 0;
		int currentHealth = 0;
		int armor = 0;
		int evadePotential = 0;
		int attackPotential = 0;
		Weapon weapon ;
		bool alive = true;
		bool magical = false;

	public:
		Entity();
		Entity(const std::string name, const int maxHealth, const int currentHealth, const int armor,
			const int evadePotential, const int attackPotential, const Weapon weapon, const bool alive, const bool magical);
		Entity(const Entity&);
		
		//Setters for class attributes
		inline void setName(const std::string& name) { this->name = name; }
		inline void setMaxHealth(const int maxHealth) { this->maxHealth = maxHealth; }
		inline void setCurrentHealth(const int currentHealth) { this->currentHealth = currentHealth; }
		inline void setArmor(const int armor) { this->armor = armor; }
		inline void setEvadePotential(const int evadePotential) { this->evadePotential = evadePotential; }
		inline void setAttackPotential(const int attackPotential) { this->attackPotential = attackPotential; }
		inline void setWeapon(const Weapon weapon) { this->weapon = weapon; }
		inline void setMagical(const bool magical) { this->magical = magical; }


		//Getters
		inline auto getName() const -> const std::string& { return name; }
		inline auto getMaxHealth() const -> const int { return maxHealth; }
		inline auto getCurrentHealth() const -> const int { return currentHealth; }
		inline auto getArmor()const -> const int { return armor; }
		inline auto getEvadePotential() const -> const int { return evadePotential; }
		inline auto getAttackPotential() const -> const int { return attackPotential; }
		inline auto getWeapon() const -> const Weapon& { return weapon; }
		inline auto isAlive() const -> const bool { return alive; }
		inline auto isMagical() const -> const bool { return magical; }
		void takeDamage(int damage);
};		

