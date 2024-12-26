#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe merge;

	if (ac < 2)
	{
		std::cerr << "Error: \"./PmergeMe 3 5 9 7 4\"" << std::endl;
		return EXIT_FAILURE;
	}
	if (!merge.initPmerge(av))
		return EXIT_FAILURE;
	merge.raceTime();
	return EXIT_SUCCESS;
}
