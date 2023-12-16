#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# define DEFAULT "\033[0m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"

# include <iostream>
# include <cstdlib>

class	WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal(void);
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &obj);
		~WrongAnimal(void);
		WrongAnimal	&operator=(const WrongAnimal &obj);
		void		makeSound(void) const;
		std::string	getType(void) const;
};

#endif
