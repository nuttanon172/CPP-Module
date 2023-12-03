#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &club) : club_type(club.getType())
{
	this->name = name;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attack with their " << club_type << std::endl;
}
