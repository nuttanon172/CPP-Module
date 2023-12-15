#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << BLUE << "Brain has created" << DEFAULT << std::endl;
}

Brain::Brain(const Brain &obj)
{
	std::cout << BLUE << "Brain has created" << DEFAULT << std::endl;
}

Brain::~Brain(void)
{
	std::cout << BLUE << "Brain has destroyed" << DEFAULT << std::endl;
}

Brain	&Brain::operator=(const Brain &obj)
{

}
