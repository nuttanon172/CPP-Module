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
	AForm *form;
	std::string type[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		for (; form_type == type[i];)
		{
			sw = i;
			break;
		}
	}
	form = NULL;
	switch (sw)
	{
	case 0:
		form = new ShrubberyCreationForm(target);
		break;
	case 1:
		form = new RobotomyRequestForm(target);
		break;
	case 2:
		form = new PresidentialPardonForm(target);
		break;
	default:
		std::cerr << "Form name passed as parameter doesn't exist\n";
	}
	std::cout << "Intern creates " << form_type + " form" << std::endl;
	return (form);
}
