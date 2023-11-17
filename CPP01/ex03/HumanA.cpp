#include "HumanA.hpp"

HumanA::HumanA(void)
{

}

HumanA::HumanA(std::string name, Weapon club)
{
	this->name = name;
	this->club = club.
}

HumanA::~HumanA(void)
{
	std::cout << this->name << ": is dead" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->name << ": attack with their " << this->club.getType() << std::endl;
}
