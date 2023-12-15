#ifndef BRAIN_HPP
# define BRAIN_HPP

# define BLUE "\033[1;34m"
# define DEFAULT "\033[0m"

# include <iostream>

class	Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain(void);
		Brain(const Brain &obj);
		~Brain(void);
		Brain	&operator=(const Brain &obj);
};

#endif
