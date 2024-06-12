#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	try {
		if (ac != 2)
			throw std::runtime_error("Program take 1 argument!!");
		ScalarConverter::convert(av[1]);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
}
