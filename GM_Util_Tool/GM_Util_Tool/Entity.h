#pragma once
enum Gender {male,female};
class Entity
{
	protected:
		int maxHealth;
		Gender gender;
		int currentHealth;
		bool alive = true;
		bool magical = false;

	public:
		void takeDamage(int damage);
		bool isAlive();
};

