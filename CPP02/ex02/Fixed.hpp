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
		Fixed	&operator=(const Fixed &obj);

		bool	operator>(const Fixed &obj) const;
		bool	operator<(const Fixed &obj) const;
		bool	operator>=(const Fixed &obj) const;
		bool	operator<=(const Fixed &obj) const;
		bool	operator==(const Fixed &obj) const;
		bool	operator!=(const Fixed &obj) const;

		float	operator+(const Fixed &obj) const;
		float	operator-(const Fixed &obj) const;
		float	operator*(const Fixed &obj) const;
		float	operator/(const Fixed &obj) const;	

		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;

		static Fixed		&min(Fixed &fp1, Fixed &fp2);
		static const Fixed	&min(const Fixed &fp1, const Fixed &fp2);
		static Fixed		&max(Fixed &fp1, Fixed &fp2);
		static const Fixed	&max(const Fixed &fp1, const Fixed &fp2);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif