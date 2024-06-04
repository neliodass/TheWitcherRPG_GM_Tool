#pragma once
#include <string>

class Weapon
{
	
	friend class PlayableCharacter;
protected:	
	std::string name = "";
	int damage = 0;
public:
	Weapon() {};
	Weapon(std::string name,int damage);
	inline void setName(const std::string name)  { this->name = name; }
	inline void setDamage(const int damage)  { this->damage = damage; }
	inline auto getName()  -> const std::string& { return name; }
	inline auto getDamage() -> const int { return damage; }

};

