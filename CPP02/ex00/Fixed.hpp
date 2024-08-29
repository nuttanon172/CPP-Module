#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _fp_nbr;
	static const int _frac_bits;

public:
	Fixed(void);
	Fixed(const Fixed &obj);
	~Fixed(void);
	Fixed &operator=(const Fixed &a);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif