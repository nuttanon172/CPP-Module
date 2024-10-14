#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "utils.hpp"
class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &obj);
	ScalarConverter &operator=(const ScalarConverter &obj);
	~ScalarConverter();

public:
	static void convert(std::string str);
};

#endif
