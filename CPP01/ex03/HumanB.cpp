#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

void	HumanB::setWeapon(Weapon &club)
{
	this->club_type = &club.getType();
}

void	HumanB::attack(void)
{
	std::cout << this->name << " attack with their " << *club_type << std::endl;
}
