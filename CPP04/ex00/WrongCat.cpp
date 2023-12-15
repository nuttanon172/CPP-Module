#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << YELLOW << this->type << " has created" << DEFAULT << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	std::cout << YELLOW << this->type << " has created" << DEFAULT << std::endl;
}

WrongCat::WrongCat::~WrongCat(void)
{
	std::cout << YELLOW << this->type << " has destroyed" << DEFAULT << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow Meow!!" << std::endl;
}
