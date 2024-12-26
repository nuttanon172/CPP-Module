#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: ./btc input.txt" << std::endl;
		return EXIT_FAILURE;
	}
	std::ifstream inputFile(av[1]);
	std::ifstream dataFile("data.csv");
	BitcoinExchange exchange;
	if (!dataFile.is_open())
	{
		std::cerr << "Error: could not open data.csv file." << std::endl;
		return EXIT_FAILURE;
	}
	if (!inputFile.is_open())
	{
		dataFile.close();
		std::cerr << "Error: could not open input file." << std::endl;
		return EXIT_FAILURE;
	}
	if (exchange.readFiles(dataFile) != true)
		return dataFile.close(), inputFile.close(), EXIT_FAILURE;
	exchange.trade(inputFile);
	dataFile.close();
	inputFile.close();
	return EXIT_SUCCESS;
}
