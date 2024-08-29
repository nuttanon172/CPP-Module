#include "iter.hpp"

int main()
{
	{
		int arr[5] = {1, 2, 3, 4, 5};

		iter(arr, 5, func<int>);
	}
	{
		std::string arr[5] = {"one", "two", "three", "four", "five"};

		iter(arr, 5, func<std::string>);
	}
	return (0);
}
