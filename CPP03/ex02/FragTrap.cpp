#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Unknown")
{
	this->_name = "Unknown";
	this->_hp = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout << "FlagTrap " << _name << " has created" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hp = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout << "FlagTrap " << _name << " has created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj._name)
{
	*this = obj;
	std::cout << "FlagTrap " << _name << " has created" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FlagTrap " << _name << " has detroyed" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &obj)
{
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_hp = obj._hp;
		this->_energy = obj._energy;
		this->_damage = obj._damage;
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_energy > 0)
	{
		std::cout << "FlagTrap " << this->_name << " highfive to everyone!!!" << std::endl;
		this->_energy -= 1;
	}
	else
		std::cout << "FlagTrap " << this->_name << " does not have enough energy to highfive" << std::endl;	
}
