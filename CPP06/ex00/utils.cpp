#include "utils.hpp"

void isCorrect(char *av)
{
	size_t i = 0;
	size_t count_f = 0;
	size_t count_dot = 0;
	size_t count_arithmetic = 0;

	if (!av)
		return;
	while (av[i])
	{
		if (!strcmp(av, "nan") || !strcmp(av, "nanf") || !strcmp(av, "inf") || !strcmp(av, "inff") ||
			!strcmp(av, "+inf") || !strcmp(av, "+inff") || !strcmp(av, "-inf") || !strcmp(av, "-inff"))
			return;
		else if ((av[0] == '+' || av[0] == '-') && !count_arithmetic)
			count_arithmetic++;
		else if (av[i] == 'f' && !count_f)
			count_f++;
		else if (av[i] == '.' && !count_dot)
			count_dot++;
		else if (av[i] < '0' || av[i] > '9')
			throw std::runtime_error("Convert failed");
		if ((av[i] == 'f' && av[i + 1] != '\0') || (av[i] == 'f' && !count_dot))
			throw std::runtime_error("Convert failed");
		i++;
	}
}

void printChar(double &d, bool &impossible)
{
	char c = static_cast<char>(d);
	std::cout << "char: ";
	if (d == -std::numeric_limits<double>::infinity() || d == std::numeric_limits<double>::infinity() ||
		d == std::numeric_limits<double>::quiet_NaN() || impossible)
		std::cout << strError(IMPOSSIBLE) << '\n';
	else if (!isprint(c) || d < 0 || d > 127)
		std::cout << strError(NONDISPLAY) << '\n';
	else
		std::cout << '\'' << c << '\'' << '\n';
}

void printInt(double &d, bool &impossible)
{

	std::cout << "int: ";
	if (d == -std::numeric_limits<double>::infinity() || d == std::numeric_limits<double>::infinity() ||
		d == std::numeric_limits<double>::quiet_NaN() || impossible)
		std::cout << strError(IMPOSSIBLE) << '\n';
	else
		std::cout << static_cast<int>(d) << '\n';
}

void printFloat(double &d)
{
	std::cout << std::fixed << "float: " << std::setprecision(1) << static_cast<float>(d) << 'f' << '\n';
}

void printDouble(double &d)
{
	std::cout << "double: " << std::setprecision(1) << d << '\n';
}

std::string strError(bool err)
{
	return (err ? "Non displayable" : "impossible");
}
