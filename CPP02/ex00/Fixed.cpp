#include "Fixed.hpp"

const int	Fixed::_frac_bits = 42;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fp_nbr = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fp_nbr = obj._fp_nbr;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fp_nbr = obj.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fp_nbr);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fp_nbr = raw;
}
