#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string			c_name;
		const std::string	*c_club;
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon &club);
		void	attack(void);
};

#endif
