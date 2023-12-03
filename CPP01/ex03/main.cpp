#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	{
		Weapon	club = Weapon("crude spike club");
		
		HumanA	bob = HumanA("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spike club");
		
		HumanB	jim = HumanB("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}
