#include "Fixed.hpp"

const int	Fixed::_frac_bits = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fp_nbr = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fp_nbr = obj.getRawBits();
}

Fixed::Fixed(const int _fp_nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fp_nbr = _fp_nbr << this->_frac_bits;
}

Fixed::Fixed(const float _fp_nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fp_nbr = roundf(_fp_nbr * (1 << this->_frac_bits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_fp_nbr = obj.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_fp_nbr);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fp_nbr = raw * (1 << this->_frac_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)_fp_nbr / (1 << this->_frac_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_fp_nbr >> this->_frac_bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
