#include "Fixed.hpp"

const int	Fixed::_frac_bits = 8;

Fixed::Fixed(void)
{
	this->_fp_nbr = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	*this = obj;
}

Fixed::Fixed(const int _fp_nbr)
{
	this->_fp_nbr = _fp_nbr << this->_frac_bits;
}

Fixed::Fixed(const float _fp_nbr)
{
	this->_fp_nbr = roundf(_fp_nbr * (1 << this->_frac_bits));
}

Fixed::~Fixed(void)
{

}

Fixed &Fixed::operator=(const Fixed &obj)
{
	if (this != &obj)
		this->_fp_nbr = obj.getRawBits();
	return (*this);
}

bool	Fixed::operator<(const Fixed &obj) const
{
	return (this->toFloat() < obj.toFloat());
}

bool	Fixed::operator<=(const Fixed &obj) const
{
	return (this->toFloat() <= obj.toFloat());
}

bool	Fixed::operator>(const Fixed &obj) const
{
	return (this->toFloat() > obj.toFloat());
}

bool	Fixed::operator>=(const Fixed &obj) const
{
	return (this->toFloat() >= obj.toFloat());
}

bool	Fixed::operator==(const Fixed &obj) const
{
	return (this->toFloat() == obj.toFloat());
}

bool	Fixed::operator!=(const Fixed &obj) const
{
	return (this->toFloat() != obj.toFloat());
}

float	Fixed::operator+(const Fixed &obj) const
{
	return (this->toFloat() + obj.toFloat());
}

float	Fixed::operator-(const Fixed &obj) const
{
	return (this->toFloat() - obj.toFloat());
}

float	Fixed::operator*(const Fixed &obj) const
{
	return (this->toFloat() * obj.toFloat());
}

float	Fixed::operator/(const Fixed &obj) const
{
	return (this->toFloat() / obj.toFloat());
}	

Fixed	Fixed::operator++(void)
{
	_fp_nbr += (1 << this->_frac_bits);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	_fp_nbr += (1 << this->_frac_bits);
	return (tmp);
}

Fixed	Fixed::operator--(void)
{
	_fp_nbr -= (1 << this->_frac_bits);	
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	_fp_nbr -= (1 << this->_frac_bits);	
	return (tmp);
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

Fixed	&Fixed::min(Fixed &fp1, Fixed &fp2)
{
	if (fp1 <= fp2)
		return (fp1);
	else
		return (fp2);
}

const Fixed	&Fixed::min(const Fixed &fp1, const Fixed &fp2)
{
	if (fp1 <= fp2)
		return (fp1);
	else
		return (fp2);
}

Fixed	&Fixed::max(Fixed &fp1, Fixed &fp2)
{
	if (fp1 >= fp2)
		return (fp1);
	else
		return (fp2);
}

const Fixed	&Fixed::max(const Fixed &fp1, const Fixed &fp2)
{
	if (fp1 >= fp2)
		return (fp1);
	else
		return (fp2);
}
