#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie("Mr.X");
	Zombie	*zombie1;

	zombie.announce();
	randomChump("Mr.Y");
	zombie1 = newZombie("Zombie1");
	zombie1->announce();
	delete(zombie1);
	return (EXIT_SUCCESS);
}