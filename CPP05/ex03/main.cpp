#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	try
	{
		std::cout << "--------------Test 1--------------\n";
		Intern someRandomIntern;
		AForm*  rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		Bureaucrat boss("boss", 1);
		if (rrf)
		{
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete (rrf);
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "--------------Test 2--------------\n";
		Intern someRandomIntern;
		AForm*  rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		Bureaucrat boss("boss", 1);
		if (rrf)
		{
			boss.executeForm(*rrf);
			delete (rrf);
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
