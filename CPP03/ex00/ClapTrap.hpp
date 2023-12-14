#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define DEFAULT "\033[0m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"

# include <iostream>
# include <cstdlib>

class	ClapTrap
{
	private:
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
