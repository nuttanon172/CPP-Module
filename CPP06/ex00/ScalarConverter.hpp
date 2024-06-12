#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <exception>
#include <limits>
#include <cctype>
#include <iomanip>
#include <cstdlib>

class ScalarConverter{
private:
	char _c;
	int _i;
	float _f;
	double _d;
	bool _impossible;
	std::string _str;
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &obj);
	ScalarConverter &operator=(const ScalarConverter &obj);
	~ScalarConverter();
	static void convert(std::string str);
	void printData(std::string str);
	void printChar();
	void printInt();
	void printFloat();
	void printDouble();
	class NonDisplayableExeception : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class ImpossibleExeception : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif
