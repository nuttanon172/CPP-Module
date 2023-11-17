#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon(void)
{
	std::cout << this->getType() << ": has destroyed" << std::endl;
}

const std::string&	Weapon::getType(void) const
{
	return (type);
}

std::string	Weapon::setType(std::string type)
{
	this->type = type;	
}