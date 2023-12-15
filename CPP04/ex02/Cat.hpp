#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat : public Animal
{
	private:
		Brain	*_brain;
	public:
		Cat(void);
		Cat(const Cat &obj);
		~Cat(void);
		Cat		&operator=(const Cat &obj);
		void	makeSound(void) const;
		Brain	*getBrain(void) const;
};

#endif
