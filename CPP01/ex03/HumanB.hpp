#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string			_name;
		const std::string	*_club;
	public:
		HumanB(const std::string &name);
		void	setWeapon(Weapon &club);
		void	attack(void);
};

#endif
