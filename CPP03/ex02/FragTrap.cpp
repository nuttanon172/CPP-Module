#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->_hp = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout << YELLOW << "FragTrap " << this->_name << " is inheriting from ClapTrap" << DEFAULT << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout << YELLOW << "FragTrap " << this->_name << " is inheriting from ClapTrap" << DEFAULT << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout << YELLOW << "FragTrap " << this->_name << " is inheriting from ClapTrap" << DEFAULT << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << YELLOW << "FlagTrap " << _name << " has detroyed" << DEFAULT << std::endl;
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
