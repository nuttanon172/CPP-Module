#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	setPhone();
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Good Bye..." << std::endl;
}

std::string	PhoneBook::strTruncate(std::string str)
{
	return (str.length() <= 10 ? str : str.substr(0, 9) + ".");
}

void	PhoneBook::printIndex(int i)
{
	for (int i = 0; i < 46; i++)
		std::cout << "-";
	std::cout << std::endl;
	std::cout << "Index: " << i << std::endl;
	std::cout << "FirstName: " << contact[i - 1].getFirstN() << std::endl;
	std::cout << "LastName: " << contact[i - 1].getFirstN() << std::endl;
	std::cout << "NickName: " << contact[i - 1].getFirstN() << std::endl;
	std::cout << "PhoneNumber: " << contact[i - 1].getFirstN() << std::endl;
	std::cout << "DarkestSecret: " << contact[i - 1].getFirstN() << std::endl;
	for (int i = 0; i < 46; i++)
		std::cout << "-";
	std::cout << std::endl;
}

void	PhoneBook::printContact(void)
{
	for (int i = 1; i < getTotal(); i++)
	{
		std::cout << "|";
		std::cout.width(10);
		std::cout << i << " |";
		std::cout.width(10);
		std::cout <<  strTruncate(contact[i - 1].getFirstN()) << "|";
		std::cout.width(10);
		std::cout << strTruncate(contact[i - 1].getLastN()) << "|";
		std::cout.width(10);
		std::cout <<  strTruncate(contact[i - 1].getNickN()) << "|";
		std::cout << std::endl;
	}
	for (int i = 0; i < 46; i++)
		std::cout << "-";
}

void	PhoneBook::printHeader(void)
{
	std::string	i;

	for (int i = 0; i < 46; i++)
		std::cout << "-";
	std::cout << "\n|  ~Index   |~FirstName|~~LastName|~~NickName|\n";
	for (int i = 0; i < 46; i++)
		std::cout << "-";
	std::cout << std::endl;
	printContact();
	std::cout << std::endl;
	std::cout << "Enter Index to search: ";
	std::getline(std::cin, i);
	printIndex(stoi(i));
}

void	PhoneBook::setPhone(void)
{
	total = 1;
	index = 0;
}

int	PhoneBook::getIndex(void)
{
	if (index > 7)
		index = 0;
	return (index++);
}

int	PhoneBook::getTotal(void)
{
	return (total);
}

void	PhoneBook::getInput(std::string msg, std::string *str)
{
	if (std::cin.eof())
		return ;
	std::cout << msg;
	while (std::getline(std::cin, *str))
	{
		if (str->empty())
		{
			std::cout << "Contact can’t have empty fields" << std::endl;
			std::cout << msg;
			continue ;
		}
		else
			return ;
	}
}

void	PhoneBook::addContact(void)
{
	std::string f, l, n, p, d;

	getInput("first name: ", &f);
	getInput("last name: ", &l);
	getInput("nick name: ", &n);
	getInput("phone name: ", &p);
	getInput("darkest secret: ", &d);
	contact[getIndex()].setValue(f, l, n, p, d);
	if (total < 8)
		total += 1;
}
