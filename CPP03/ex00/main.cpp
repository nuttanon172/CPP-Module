#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	player("player");

	for (int i = 0; i < 12; i++)
		player.attack("Monster");
	player.takeDamage(10);
	player.beRepaired(1);
	player.takeDamage(1);
	return (EXIT_SUCCESS);
}
