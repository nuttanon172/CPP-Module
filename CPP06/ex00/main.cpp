#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
		std::cerr << "Program take 1 argument!!" << std::endl;
	int a = 42;
	double b = a;
	double c = (double)a;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
}
