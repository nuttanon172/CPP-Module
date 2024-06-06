#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter{
private:
	char c;
	int i;
	float f;
	double d;
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &obj);
	ScalarConverter &operator=(const ScalarConverter &obj);
	~ScalarConverter();
	static void convert();
};

#endif
