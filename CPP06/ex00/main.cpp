#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	try {
		if (ac != 2)
			std::cerr << "Program take 1 argument!!" << std::endl;
		ScalarConverter::convert(av[1]);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
}
