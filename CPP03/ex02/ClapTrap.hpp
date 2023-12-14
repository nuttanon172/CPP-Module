#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <cstdlib>

class	ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_energy;
		unsigned int	_damage;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &obj);
		~ClapTrap(void);
		ClapTrap	&operator=(const ClapTrap &obj);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

};

#endif
