#include "Zombie.hpp"

int main(void)
{
	int N = 5;
	Zombie *zombie = zombieHorde(N, "ZombieX");
	for (int i = 0; i < N; i++)
		zombie[i].announce();
	delete[] zombie;
	return (EXIT_SUCCESS);
}