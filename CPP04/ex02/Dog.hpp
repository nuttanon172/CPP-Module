#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
	Brain *_brain;

public:
	Dog(void);
	Dog(const Dog &obj);
	~Dog(void);
	Dog &operator=(const Dog &obj);
	void makeSound(void) const;
	Brain *getBrain(void) const;
};

#endif
