#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(const WrongCat &obj);
	~WrongCat(void);
	WrongCat &operator=(const WrongCat &obj);
	void makeSound(void) const;
};

#endif
