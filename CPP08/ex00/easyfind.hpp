#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

template <typename T>
void easyfind(const T &container, const int &nbr)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), nbr);
	if (it != container.end())
		std::cout << "parameter found at position " << (it - container.begin()) << std::endl;
	else
		throw std::out_of_range("parameter not found");
}


#endif
