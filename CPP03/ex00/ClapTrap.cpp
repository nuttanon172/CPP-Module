#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Unknow"), _hp(10), _energy(10), _damage(0)
{
	std::cout << _name << " has created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _energy(10), _damage(0)
{
	std::cout << "ClapTrap " << _name << " has created" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &obj)
{
	*this = obj;
	std::cout << "ClapTrap " << _name << "has created" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &obj)
{
	if (this == &obj)
		return (*this);
	this->_name = obj._name;
	this->_hp = obj._hp;
	this->_energy = obj._energy;
	this->_damage = obj._damage;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap "<< _name << " has destroyed" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energy > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks ";
		std::cout << target <<", causing " << this->_damage << " points of damage!" << std::endl;
		this->_energy -= 1;
	}
	else
		std::cout << "ClapTrap " << this->_name << " does not have enough energy." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp >= amount)
	{
		std::cout << "ClapTrap " << this->_name << " has taken " << amount << " damage" << std::endl;
		this->_hp -= amount;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " has taken " << amount << " damage" << std::endl;
		this->_hp = 0;
	}
	if (!this->_hp)
		std::cout << "ClapTRap " << this->_name << " is dead" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy > 0)
	{
		this->_hp += amount;
		std::cout << "ClapTrap " << this->_name << "be repaired " << amount << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " does not have enough energy." << std::endl;
}
