#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string			name;
		const std::string	*club_type;
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon &club);
		void	attack(void);
};

#endif
