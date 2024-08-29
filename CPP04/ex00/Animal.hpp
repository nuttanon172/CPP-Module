#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define DEFAULT "\033[0m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"

#include <iostream>
#include <cstdlib>

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(const std::string &type);
	Animal(const Animal &obj);
	virtual ~Animal(void);
	Animal &operator=(const Animal &obj);
	virtual void makeSound(void) const;
	std::string getType(void) const;
};

#endif
