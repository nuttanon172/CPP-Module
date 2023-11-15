#include "PhoneBook.hpp"

int	main(void)
{
	std::string	str;
	PhoneBook	pb;

	while (1)
	{
		std::cout << "Enter Command: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (EXIT_SUCCESS);
		}
		else if (!str.compare("ADD"))
			pb.addContact();
		else if (!str.compare("SEARCH"))
			pb.printHeader();
		else if (!str.compare("EXIT"))
			return (EXIT_SUCCESS);
	}
}
