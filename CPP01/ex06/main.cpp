#include "Harl.hpp"

void	switch_cp(std::string level)
{
	Harl	obj;
	size_t	sw;
	
	std::string	cmd[4] = {"debug", "info", "warning", "error"};
	for (size_t i = 0; i < 4; i++)
		if (level == cmd[i])
			sw = i;
	switch (sw)
	{
		case 0:
			obj.complain("debug");
		case 1:
			obj.complain("info");
		case 2:
			obj.complain("warning");
		case 3:
		{
			obj.complain("error");
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
		std::cout << "HarlFilter take atleast 1 argument" << std::endl;
		return (1);
	}
	switch_cp((std::string)av[1]);
	return (0);
}