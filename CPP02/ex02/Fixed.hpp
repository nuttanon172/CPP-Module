#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					_fp_nbr;
		static const int	_frac_bits;
	public:
		Fixed(void);
		Fixed(const Fixed &obj);
		Fixed(const int _fp_nbr);
		Fixed(const float _fp_nbr);
		~Fixed(void);
		Fixed	&operator=(const Fixed &a);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif