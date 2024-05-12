#include "Intern.hpp"
Intern::Intern()
{
	std::cout << "Intern has created\n";
}

Intern::Intern(const Intern &obj)
{
	(void)obj;
	std::cout << "Intern has created\n";
}

Intern::~Intern()
{
	std::cout << "Intern has destroyed\n";
}

Intern &Intern::operator=(const Intern &obj)
{
	(void)obj;
	return (*this);
}

AForm *Intern::makeForm(const std::string &form_type, const std::string &target)
{
	int sw = 4;
	std::string	type[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		for (;form_type == type[i];)
		{
			sw = i;
			break ;
		}
	}
	switch (sw)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			std::cerr << "Form name passed as parameter doesn't exist" << std::endl;
	}
	return (NULL);
}
