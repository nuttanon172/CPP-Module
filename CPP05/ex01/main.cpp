#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Form a;
		std::cout << a << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}
}
