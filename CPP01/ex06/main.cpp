#include "Harl.hpp"

int	main(void)
{
	Harl		obj;
	std::string	str;

	obj.complain("debug");
	obj.complain("info");
	obj.complain("warning");
	obj.complain("error");
}