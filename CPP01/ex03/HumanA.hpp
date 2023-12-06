#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string			c_name;
		const std::string	&c_club;
	public:
		HumanA(std::string name, Weapon &club);
		void	attack(void);
};

#endif
