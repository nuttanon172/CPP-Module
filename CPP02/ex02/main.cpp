#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	// Fixed		a = 1.01f;
	// Fixed const	b(Fixed(5.05f) * Fixed(2));

	// std::cout << "(a: " << a <<  ", b: " << b << ")" << std::endl;
	// std::cout << (0.999999f) + (0.000001f) << std::endl;
	// std::cout << "a > b " << (a > b) << std::endl;
	// std::cout << "a < b " << (a < b) << std::endl;
	// std::cout.width(6);
	// std::cout << "a : " << a << std::endl;
	// std::cout.width(6);
	// std::cout << "++a : " << ++a << std::endl;
	// std::cout.width(6);
	// std::cout << "a : " << a << std::endl;
	// std::cout.width(6);
	// std::cout << "a++ : " << a++ << std::endl;
	// std::cout.width(6);
	// std::cout << "a : " << a << std::endl;
	// std::cout << std::endl;

	// std::cout << "(a: " << a <<  ", b: " << b << ")" << std::endl;
	// std::cout.width(6);
	// std::cout << "a : " << a << std::endl;
	// std::cout.width(6);
	// std::cout << "--a : " << --a << std::endl;
	// std::cout.width(6);
	// std::cout << "a : " << a << std::endl;
	// std::cout.width(6);
	// std::cout << "a-- : " << a-- << std::endl;
	// std::cout.width(6);
	// std::cout << "a : " << a << std::endl;
	// std::cout << std::endl;

	//// Max Min
	// std::cout << "(a: " << a <<  ", b: " << b << ")" << std::endl;
	// std::cout.width(11);
	// std::cout << "Max(a,b) : " << Fixed::max(a, b) << std::endl;
	// std::cout.width(11);
	// std::cout << "Min(a,b) : " << Fixed::min(a, b) << std::endl;
	// std::cout << std::endl;

	//// + - * /
	// std::cout << "(a: " << a <<  ", b: " << b << ")" << std::endl;
	// std::cout.width(8);
	// std::cout << "a + b : " << a + b << std::endl;
	// std::cout.width(8);
	// std::cout << "a - b : " << a - b << std::endl;
	// std::cout.width(8);
	// std::cout << "a * b : " << a * b << std::endl;
	// std::cout.width(8);
	// std::cout << "a / b : " << a / b << std::endl;
	// std::cout << std::endl;
	// return (EXIT_SUCCESS);
}
