#include "HumanB.hpp"

HumanB::HumanB(std::string name) : c_name(name)
{
	
}

void	HumanB::setWeapon(Weapon &club)
{
	c_club = &club.getType();
}

void	HumanB::attack(void)
{
	std::cout << c_name << " attack with their " << *c_club << std::endl;
}
