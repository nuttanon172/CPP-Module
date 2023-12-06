#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &club) : c_name(name), c_club(club.getType())
{

}

void	HumanA::attack(void)
{
	std::cout << c_name << " attack with their " << c_club << std::endl;
}
