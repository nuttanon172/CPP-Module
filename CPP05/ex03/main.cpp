#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
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
