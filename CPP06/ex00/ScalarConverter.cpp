#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	_c = 0;
	_i = 0;
	_f = 0;
	_d = 0;
	_impossible = false;
	_str = "";
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{

}

//ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
//{

//}

ScalarConverter::~ScalarConverter()
{

}

void ScalarConverter::func(std::string str)
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
		_d = strtod(str.c_str(), NULL);
		if (_str[0] != '0' && _d == 0)
			throw NonDisplayableExeception();
		if (_d > std::numeric_limits<int>::max() || _d < std::numeric_limits<int>::min())
			_impossible = true;
		_c = static_cast<char>(_d);
		_i = static_cast<int>(_d);
		_f = static_cast<float>(_d);
	}
	printChar();
	printDouble();
	printFloat();
	printInt();
} 

void ScalarConverter::convert(std::string str)
{
	ScalarConverter sc;
	sc.func(str);
}

void ScalarConverter::printChar()
{
	try {
		if (_d == -std::numeric_limits<double>::infinity() || _d == std::numeric_limits<double>::infinity() || _d == std::numeric_limits<double>::quiet_NaN())
			throw ImpossibleExeception();
		else if (!isprint(_c))
			throw NonDisplayableExeception();
		else if (_impossible)
			throw ImpossibleExeception();
		else
			std::cout << "char: " << _c << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << "char: " << e.what() << '\n';
	}
}

void ScalarConverter::printInt()
{
	try {
		if (_d == -std::numeric_limits<double>::infinity() || _d == std::numeric_limits<double>::infinity() || _d == std::numeric_limits<double>::quiet_NaN())
			throw ImpossibleExeception();
		else if (_impossible)
			throw ImpossibleExeception();
		else
			std::cout << "int: " << _i << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << "int: " << e.what() << '\n';
	}
}

void ScalarConverter::printFloat()
{
	try {
		if (_d == -std::numeric_limits<double>::infinity() || _d == std::numeric_limits<double>::infinity())
			throw ImpossibleExeception();
		else if (_impossible)
			throw ImpossibleExeception();		
		else
			std::cout << "float: " << _f << 'f' << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << "float: " << e.what() << 'f' << '\n';
	}
}

void ScalarConverter::printDouble()
{
	try {
		if (_d == -std::numeric_limits<double>::infinity() || _d == std::numeric_limits<double>::infinity())
			throw ImpossibleExeception();
		else if (_impossible)
			throw ImpossibleExeception();		
		else
			std::cout << "double: " << _d << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << "double: " << e.what() << '\n';
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
