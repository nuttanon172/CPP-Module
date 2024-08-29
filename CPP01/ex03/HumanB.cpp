#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name)
{
	this->_club = NULL;
}

void HumanB::setWeapon(Weapon &club)
{
	this->_club = &club.getType();
}

void HumanB::attack(void)
{
	if (this->_club)
		std::cout << _name << " attack with their " << *(this->_club) << std::endl;
	else
		std::cout << _name << " lost their club" << std::endl;
}
