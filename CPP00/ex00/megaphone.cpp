#include <iostream>
#include <cctype>
#include <cstdlib>

void print_upper(char *av)
{
	for (int j = 0; av[j]; j++)
		std::cout << (char)toupper(av[j]);
}

int main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; av[i]; i++)
			print_upper(av[i]);
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}