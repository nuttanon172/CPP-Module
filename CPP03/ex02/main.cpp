#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	player1("player1");
	FragTrap	player3("player2");
	FragTrap	player2(player3);
	ScavTrap	player4;

	for (int i = 0; i < 11; i++)
		player1.attack("Monster");
	for (int i = 0; i < 11; i++)
		player4.attack("Monster");
	for (int i = 0; i < 11; i++)
		player2.highFivesGuys();
	player1.takeDamage(10);
	player1.beRepaired(1);
	player1.takeDamage(1);
	player2.takeDamage(100);
	player2.beRepaired(10);
	player2.takeDamage(9);
	player4.beRepaired(1);
	ScavTrap	p1("p1");
	p1.takeDamage(50);
	ScavTrap	p2(p1);
	p2.takeDamage(50);
	return (EXIT_SUCCESS);
}
