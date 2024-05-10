#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat k1("test1", 150);
		std::cout << k1.getName() << '\n';
		k1.incGrade();
		std::cout << k1.getGrade() << '\n';
		k1.decGrade();
		std::cout << k1.getGrade() << '\n';
		//k.decGrade();
		//std::cout << k.getGrade() << '\n';
		Bureaucrat k2("test2", 1);
		std::cout << k2.getName() << '\n';
		//k2.incGrade();
		std::cout << k2.getGrade() << '\n';
		k2.decGrade();
		std::cout << k2.getGrade() << '\n';
		std::cout << k2 << '\n';
		std::cout << "-------------------------------\n";
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}
}
