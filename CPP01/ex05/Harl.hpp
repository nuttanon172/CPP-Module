#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <cstdlib>

class	Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		void	complain(std::string level);
		typedef void	(Harl::*func_ar)();
};

#endif