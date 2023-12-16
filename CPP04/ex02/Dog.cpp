#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog")
{
	this->_brain = new Brain();
	std::cout << YELLOW << this->type << " has created" << DEFAULT << std::endl;
}

Dog::Dog(const Dog &obj) : AAnimal(obj)
{
	this->_brain = new Brain(*obj.getBrain());
	std::cout << YELLOW << this->type << " has created" << DEFAULT << std::endl;
}

Dog::Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << YELLOW << this->type <<" has destroyed" << DEFAULT << std::endl;
}

Dog	&Dog::operator=(const Dog &obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
		this->_brain = new Brain(*obj.getBrain());
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof!!" << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}
