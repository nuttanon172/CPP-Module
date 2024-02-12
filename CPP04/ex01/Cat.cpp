#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	this->_brain = new Brain();
	std::cout << YELLOW << this->type << " has created" << DEFAULT << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	this->_brain = new Brain(*obj.getBrain());
	std::cout << YELLOW << this->type << " has created" << DEFAULT << std::endl;
}

Cat::Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << YELLOW << this->type << " has destroyed" << DEFAULT << std::endl;
}

Cat	&Cat::operator=(const Cat &obj)
{
	if (this != &obj)
	{
		delete this->_brain;
		this->type = obj.type;
		this->_brain = new Brain(*obj.getBrain());
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow!!" << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	return (this->_brain);	
}
