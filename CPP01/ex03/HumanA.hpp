#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string			name;
		const std::string	club;
	public:
		HumanA(void);
		HumanA(std::string name, Weapon club);
		~HumanA(void);
		void	attack(void);
};

#endif
