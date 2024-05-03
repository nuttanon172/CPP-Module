#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat k("test", 151);
		std::cout << k.getName() << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << "\n";
	}
}
