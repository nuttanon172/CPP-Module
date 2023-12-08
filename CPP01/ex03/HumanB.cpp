#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{

}

void	HumanB::setWeapon(Weapon &club)
{
	_club = &club.getType();
}

void	HumanB::attack(void)
{
	std::cout << _name << " attack with their " << *_club << std::endl;
}
