#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << YELLOW << this->type << " has created" << DEFAULT << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << YELLOW << this->type << " has created" << DEFAULT << std::endl;
}

Dog::Dog::~Dog(void)
{
	std::cout << YELLOW << this->type <<" has destroyed" << DEFAULT << std::endl;
}

Dog	&Dog::operator=(const Dog &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof!!" << std::endl;
}
