#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("AAnimal")
{
	std::cout << GREEN << "AAnimal " << this->type << " has created" << DEFAULT << std::endl;
}

AAnimal::AAnimal(const std::string &type) : type(type)
{
	std::cout << GREEN << "AAnimal " << this->type << " has created" << DEFAULT << std::endl;
}

AAnimal::AAnimal(const AAnimal &obj)
{
	*this = obj;
	std::cout << GREEN << "AAnimal " << this->type << " has created" << DEFAULT << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << GREEN << "AAnimal " << this->type << " has destroyed" << DEFAULT << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "..." << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (this->type);
}
