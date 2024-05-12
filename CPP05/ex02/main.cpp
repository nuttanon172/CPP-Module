#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	std::cout << "--------------Test 1--------------\n";
	PresidentialPardonForm form("Someone");
	Bureaucrat bu("Boss", 1);

	bu.executeForm(form);

	try
	{
		std::cout << "--------------Test 2--------------\n";
		PresidentialPardonForm form("Someone");
		Bureaucrat bu("Boss", 150);

		bu.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "--------------Test 3--------------\n";
		RobotomyRequestForm form("Someone");
		Bureaucrat bu("Boss", 40);

		bu.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "--------------Test 4--------------\n";
		ShrubberyCreationForm form("Someone");
		Bureaucrat bu("Boss", 150);

		bu.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
