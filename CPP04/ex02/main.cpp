#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void)
{
	AAnimal *meta[10];
	for (int i = 0; i < 5; i++)
		meta[i] = new Cat();
	for (int i = 5; i < 10; i++)
		meta[i] = new Dog();
	for (int i = 0; i < 10; i++)
	{
		std::cout << meta[i]->getType() << ": ";
		meta[i]->makeSound();
		std::cout << std::endl;
	}
	for (int i = 0; i < 10; i++)
		delete meta[i];
	std::cout << "\n~~~Brain DeepCopy Test~~~\n" << std::endl;
	Brain C;
	C.displayIdeas();
	C.setIdeas("Woof!");
	Brain D(C);
	C.setIdeas("Meow!");
	C.displayIdeas();
	std::cout << std::endl;
	D.displayIdeas();
	return (EXIT_SUCCESS);
}
