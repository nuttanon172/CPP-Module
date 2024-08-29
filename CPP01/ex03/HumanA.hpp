#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	const std::string &_club;

public:
	HumanA(const std::string &name, Weapon &club);
	void attack(void);
};

#endif
