#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Form a("formA", 123, 123);
	Bureaucrat b("buA", 122);
	Bureaucrat c("buB", 124);
	b.signForm(a);
	c.signForm(a);
	std::cout << "--------------------------------------------------\n";
	std::cout << b << '\n';
	std::cout << a << '\n';
	std::cout << "--------------------------------------------------\n";
	try
	{
		Form D("formD", -123, 150);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << '\n';
		std::cout << "--------------------------------------------------\n";
	}
	try
	{
		Form E("formE", 100, 100);
		Bureaucrat F("buF", 124);
		E.beSigned(F);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << '\n';
		std::cout << "--------------------------------------------------\n";
	}
}
