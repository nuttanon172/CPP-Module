#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <class T>
class Array{
private:
	unsigned int arr_size;
	T *arr_data;
public:
	Array<T>()
	{
		arr_size = 0;
		arr_data = NULL;
		std::cout << "Array has created" << std::endl;
	}
	Array<T>(unsigned int n)
	{
		arr_size = n;
		arr_data = new T[n];
		std::cout << "Array has created " << n << " elements" << std::endl;
	}
	Array<T>(const Array &obj)
	{
		arr_size = obj.size();
		arr_data = new T[obj.size()];
		for (unsigned int i = 0; i < obj.size();i++)
			arr_data[i] = obj.arr_data[i];
	}
	Array<T> &operator=(const Array<T> &obj)
	{
		if (this != &obj)
		{
			delete[] arr_data;
			arr_size = obj.size();
			arr_data = new T[obj.size()];
			for (unsigned int i = 0; i < obj.size();i++)
				arr_data[i] = obj.arr_data[i];
		}
		return (*this);
	}
	~Array<T>()
	{
		if (arr_data)
			delete[] arr_data;
		std::cout << "Array has destroyed" << std::endl;
	}
	unsigned int size() const
	{ 
		return (arr_size); 
	}
	T &operator[](unsigned int index) const
	{
		if (index >= arr_size)
			throw Array<T>::OutOfBoundException();
		else
			return (arr_data[index]);
	}
	class OutOfBoundException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Index is out of bounds");
			}
	};
};

#endif
