#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(char *av)
{
	
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{

}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{

}

ScalarConverter::~ScalarConverter()
{

}

void ScalarConverter::convert(std::string str)
{
	_str = str;
	if (_str == "nan")
		_d = std::numeric_limits<double>::quiet_NaN();
	else if (_str == "+inf" || _str == "+inff")
		_d = std::numeric_limits<double>::infinity();
	else if (_str == "-inf" || _str == "-inff")
		_d = -std::numeric_limits<double>::infinity();
	else
	{
		
	}
}

const char	*ScalarConverter::NonDisplayableExeception::what() const throw()
{
	return ("Non displayable");
}

const char	*ScalarConverter::ImpossibleExeception::what() const throw()
{
	return ("impossible");
}
