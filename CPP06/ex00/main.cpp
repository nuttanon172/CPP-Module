#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::runtime_error("Program take 1 argument");
		isCorrect(av[1]);
		ScalarConverter::convert(av[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}
