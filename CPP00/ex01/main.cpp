#include "PhoneBook.hpp"

int	main(void)
{
	std::string	str;
	PhoneBook	pb;

	std::cout << "Enter Command: ";
	while (std::getline(std::cin, str))
	{
		if (!str.compare("ADD"))
			pb.addContact();
		else if (!str.compare("SEARCH"))
			pb.printHeader();
		else if (!str.compare("EXIT"))
			return (EXIT_SUCCESS);
		else
			std::cout << "Command not found.." << std::endl;
		if (!std::cin.eof())
			std::cout << "Enter Command: ";
	}
	return (EXIT_SUCCESS);
}
