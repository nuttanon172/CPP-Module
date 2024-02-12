#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &club) : _name(name), _club(club.getType())
{

}

void	HumanA::attack(void)
{
	std::cout << _name << " attack with their " << _club << std::endl;
}
