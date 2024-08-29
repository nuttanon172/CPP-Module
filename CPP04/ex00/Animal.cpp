#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << GREEN << "Animal " << this->type << " has created" << DEFAULT << std::endl;
}

Animal::Animal(const std::string &type) : type(type)
{
	std::cout << GREEN << "Animal " << this->type << " has created" << DEFAULT << std::endl;
}

Animal::Animal(const Animal &obj)
{
	this->type = obj.type;
	std::cout << GREEN << "Animal " << this->type << " has created" << DEFAULT << std::endl;
}

Animal::~Animal(void)
{
	std::cout << GREEN << "Animal " << this->type << " has destroyed" << DEFAULT << std::endl;
}

Animal &Animal::operator=(const Animal &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout << "..." << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->type);
}
