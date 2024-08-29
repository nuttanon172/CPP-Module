#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat k1("test1", 150);
		std::cout << k1 << '\n';
		k1.incGrade();
		std::cout << k1 << '\n';
		k1.decGrade();
		std::cout << k1 << '\n';

		Bureaucrat k2("test2", 1);
		std::cout << k2 << '\n';
		// k2.incGrade();
		std::cout << k2 << '\n';
		k2.decGrade();
		std::cout << k2 << '\n';
		std::cout << "-------------------------------\n";
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}
}
