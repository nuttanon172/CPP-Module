#include "RPN.hpp"
#include "iostream"
#include "cstdlib"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: ./RPN \"{EXPRESSION}\"" << std::endl;
		return EXIT_FAILURE;
	}
	RPN r;
	r.calculate(av[1]);
	return EXIT_SUCCESS;
}
