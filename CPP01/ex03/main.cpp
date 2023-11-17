#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	{
		Weapon	club = Weapon("Crude Spike Club");

		HumanA	bob = HumanA("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
}
