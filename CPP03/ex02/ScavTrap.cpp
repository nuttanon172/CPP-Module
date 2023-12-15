#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Unknown")
{
	this->_hp = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout << BLUE << "ScavTrap " << this->_name << " is inheriting from ClapTrap" << DEFAULT << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout << BLUE << "ScavTrap " << this->_name << " is inheriting from ClapTrap" << DEFAULT << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &obj) : ClapTrap(obj)
{
	*this = obj;
	std::cout << BLUE << "ScavTrap " << this->_name << " is inheriting from ClapTrap" << DEFAULT << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << BLUE << "ScavTrap "<< _name << " has destroyed" << DEFAULT << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &obj)
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

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energy > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks ";
		std::cout << target <<", causing " << this->_damage << " points of damage!" << std::endl;
		this->_energy -= 1;
	}
	else
		std::cout << "ScavTrap " << this->_name << " does not have enough energy to attack" << std::endl;
}
