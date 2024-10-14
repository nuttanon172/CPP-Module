#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	(void)obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string str)
{
	double d;
	bool impossible(true);

	if (str == "nan" || str == "nanf")
		d = std::numeric_limits<double>::quiet_NaN();
	else if (str == "inf" || str == "inff" || str == "+inf" || str == "+inff")
		d = std::numeric_limits<double>::infinity();
	else if (str == "-inf" || str == "-inff")
		d = -std::numeric_limits<double>::infinity();
	else
	{
		impossible = false;
		d = strtod(str.c_str(), NULL);
		if (str[0] != '0' && d == 0)
			throw std::runtime_error("Convert failed");
		if (d > std::numeric_limits<int>::max())
			throw std::overflow_error("Over flow numeric");
		else if (d < std::numeric_limits<int>::min())
			throw std::underflow_error("Under flow numeric");
	}
	printChar(d, impossible);
	printInt(d, impossible);
	printFloat(d);
	printDouble(d);
}
