#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << meta->getType() << ": ";
	meta->makeSound();
	std::cout << i->getType() << ": ";
	i->makeSound();
	std::cout << j->getType() << ": ";
	j->makeSound();
	delete j;
	delete i;
	delete meta;

	std::cout << "\n~~~More Test~~~\n" << std::endl;

	return (EXIT_SUCCESS);
}
