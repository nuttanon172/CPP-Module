#include "Harl.hpp"

static void	switch_cp(std::string level)
{
	Harl	obj;
	size_t	sw = 4;
	
	std::string	cmd[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (size_t i = 0; i < 4; i++)
		if (level == cmd[i])
			sw = i;
	switch (sw)
	{
		case 0:
			obj.complain(cmd[0]);
		case 1:
			obj.complain(cmd[1]);
		case 2:
			obj.complain(cmd[2]);
		case 3:
		{
			obj.complain(cmd[3]);
			break ;
		}
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "HarlFilter must take 1 argument" << std::endl;
		return (EXIT_FAILURE);
	}
	switch_cp((std::string)av[1]);
	return (EXIT_SUCCESS);
}