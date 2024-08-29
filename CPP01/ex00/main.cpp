#include "Zombie.hpp"

int main(void)
{
	Zombie zombie("ZombieX");
	Zombie *zombie1;

	zombie.announce();
	randomChump("ZombieY");
	zombie1 = newZombie("ZombieZ");
	zombie1->announce();
	delete zombie1;
	return (EXIT_SUCCESS);
}