#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	setPhone();
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Good Bye..." << std::endl;
}

void	PhoneBook::printHeader(void)
{
	for (int i = 0; i < 46; i++)
		std::cout << "-";
	std::cout << "\n|  ~Index   |~FirstName|~~LastName|~~NickName|\n";
	for (int i = 0; i < 46; i++)
		std::cout << "-";
	std::cout << std::endl;
}

void	PhoneBook::setPhone(void)
{
	total = 0;
	index = 1;
}

int	PhoneBook::getIndex(void)
{
	if (index > 8)
		index = 0;
	return (index++);
}

int	PhoneBook::getTotal(void)
{
	if (total > 8)
		total = 8;
	return (total++);
}

void	PhoneBook::addContact(void)
{
	std::string f, l, n, p, d;

	std::cout << "first name: ";
	std::getline(std::cin, f);
	if (!std::cin.eof())
		f = "";
	std::cout << "last name: ";
	std::getline(std::cin, l);
	if (!std::cin.eof())
		l = "";
	std::cout << "nick name: ";
	std::getline(std::cin, n);
	if (!std::cin.eof())
		n = "";
	std::cout << "phone number: ";
	std::getline(std::cin, p);
	if (!std::cin.eof())
		p = "";
	std::cout << "darkest secret: ";
	std::getline(std::cin, d);
	if (!std::cin.eof())
		d = "";
	conTact[getIndex()].setValue(f, l, n, p, d);
}
