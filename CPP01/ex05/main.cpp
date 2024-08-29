#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl obj;

	if (ac < 2)
	{
		std::cerr << "Harl must take 1 argument" << std::endl;
		return (EXIT_FAILURE);
	}
	obj.complain((std::string)av[1]);
	return (EXIT_SUCCESS);
}