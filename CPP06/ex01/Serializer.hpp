#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

#define GREEN "\033[32m"
#define DEFAULT "\033[0m"

class Serializer {
private:
	Serializer();
	Serializer(const Serializer &obj);
	Serializer &operator=(const Serializer &obj);
	~Serializer();
public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif
