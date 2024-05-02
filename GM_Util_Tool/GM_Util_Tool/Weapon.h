#pragma once
#include <string>
class Weapon
{
protected:	
	std::string name;
	int damage;
public:
	Weapon();
	Weapon(std::string name,int damage);
	Weapon(const Weapon&);
};

