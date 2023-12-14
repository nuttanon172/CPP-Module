#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &obj);
		~ScavTrap(void);
		ScavTrap	&operator=(const ScavTrap &obj);
		void		attack(const std::string& target);
		void		guardGate(void);
};

#endif