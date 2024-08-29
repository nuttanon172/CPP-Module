#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap player1("player1");
	ScavTrap player3("player2");
	ScavTrap player2 = player3;

	for (int i = 0; i < 12; i++)
		player1.attack("Monster");
	for (int i = 0; i < 12; i++)
		player2.attack("Monster");
	player1.takeDamage(10);
	player1.beRepaired(1);
	player1.takeDamage(1);
	player2.takeDamage(100);
	player2.beRepaired(10);
	player2.takeDamage(9);
	return (EXIT_SUCCESS);
}
