#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	obj;

	if (ac < 2)
	{
		std::cout << "Harl take atleast 1 argument" << std::endl;
		return (1);
	}
	obj.complain((std::string)av[1]);
	return (0);
}