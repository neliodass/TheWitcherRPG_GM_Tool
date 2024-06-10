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
	int sorceryPotential = 0;
	Weapon weapon = Weapon();
	bool alive = true;
	bool magical = false;

public:
	Entity();
	Entity(const std::string name, const int maxHealth, const int currentHealth, const int armor,
		const int evadePotential, const int attackPotential, const int sorceryPotential, const Weapon weapon, const bool alive, const bool magical);

	inline void setName(const std::string name) { this->name = name; }
	inline void setMaxHealth(const int maxHealth) { this->maxHealth = maxHealth; }
	inline void setCurrentHealth(const int currentHealth) { this->currentHealth = currentHealth; }
	inline void setArmor(const int armor) { this->armor = armor; }
	inline void setEvadePotential(const int evadePotential) { this->evadePotential = evadePotential; }
	inline void setAttackPotential(const int attackPotential) { this->attackPotential = attackPotential; }
	inline void setSorceryPotential(const int sorceryPotential) { this->sorceryPotential = sorceryPotential; }
	inline void setWeapon(const Weapon weapon) { this->weapon = weapon; }
	inline void setAlive(const bool alive) { this->alive = alive; }
	inline void setMagical(const bool magical) { this->magical = magical; }

	inline const std::string& getName() const { return name; }
	inline const int getMaxHealth() const { return maxHealth; }
	inline const int getCurrentHealth() const { return currentHealth; }
	inline const int getArmor()const { return armor; }
	inline const int getEvadePotential() const { return evadePotential; }
	inline const int getAttackPotential() const { return attackPotential; }
	inline const int getSorceryPotential() const { return sorceryPotential; }
	inline Weapon& getWeapon() { return weapon; }
	inline const bool isAlive() const { return alive; }
	inline const bool isMagical() const { return magical; }
	void takeDamage(int damage);
};
