#include "Weapon.h"
#include <string>
Weapon::Weapon()
{
	
}
Weapon::Weapon(std::string name,int damage)
{
	this->name = name;
	this->damage = damage;
}
Weapon::Weapon(const Weapon&)
{

}