#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << BLUE << "WrongAnimal " << this->type << " has created" << DEFAULT << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type)
{
	std::cout << BLUE << "WrongAnimal " << this->type << " has created" << DEFAULT << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	this->type = obj.type;
	std::cout << BLUE << "WrongAnimal " << this->type << " has created" << DEFAULT << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << BLUE << "WrongAnimal " << this->type << " has destroyed" << DEFAULT << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "..." << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}
