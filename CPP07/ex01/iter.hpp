#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

// void (*func)(T) or Func from template type
template <typename T, typename Func>
void iter(T *arr, size_t size, Func func)
{
	for (size_t i = 0;i < size; i++)
		func(arr[i]);
}

template <typename T>
void func(T x)
{
	std::cout << "Value = " << x << std::endl;
}

#endif
