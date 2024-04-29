#pragma once
enum Gender {male,female};
class Entity
{
	protected:
		const int maxHealth;
		Gender gender;
		int currentHealth;
		int parry;
		int evadePotential;
		int attackPotential;
		bool alive = true;
		bool magical = false;

	public:
		void takeDamage(int damage);
		bool isAlive();
};

