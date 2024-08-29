#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &club) : _name(name), _club(club.getType())
{
}

void HumanA::attack(void)
{
	std::cout << this->_name << " attack with their " << this->_club << std::endl;
}
