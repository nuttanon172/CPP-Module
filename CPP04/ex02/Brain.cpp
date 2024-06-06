#include "Brain.hpp"

Brain::Brain(void)
{
	this->setIdeas("...");
	std::cout << BLUE << "Brain has created" << DEFAULT << std::endl;
}

Brain::Brain(const Brain &obj)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	std::cout << BLUE << "Brain has created" << DEFAULT << std::endl;
}

Brain::~Brain(void)
{
	std::cout << BLUE << "Brain has destroyed" << DEFAULT << std::endl;
}

Brain	&Brain::operator=(const Brain &obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	}
	return (*this);
}

void	Brain::displayIdeas(void) const
{
	for (int i = 0; i < 100; i++)
		std::cout << this->ideas[i] << " ";
	std::cout << std::endl;

}

void	Brain::setIdeas(const std::string ideas)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ideas;
}
