#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# define DEFAULT "\033[0m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"

# include <iostream>
# include <cstdlib>
# include "Brain.hpp"

class	AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal(void);
		AAnimal(const std::string &type);
		AAnimal(const AAnimal &obj);
		virtual ~AAnimal(void);
		AAnimal	&operator=(const AAnimal &obj);
		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
};

#endif
