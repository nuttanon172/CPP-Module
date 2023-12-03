#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string			name;
		const std::string	&club_type;
	public:
		HumanA(std::string name, Weapon &club);
		void	attack(void);
};

#endif
