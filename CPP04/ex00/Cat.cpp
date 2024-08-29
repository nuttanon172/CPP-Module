#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << YELLOW << this->type << " has created" << DEFAULT << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << YELLOW << this->type << " has created" << DEFAULT << std::endl;
}

Cat::Cat::~Cat(void)
{
	std::cout << YELLOW << this->type << " has destroyed" << DEFAULT << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow Meow!!" << std::endl;
}
