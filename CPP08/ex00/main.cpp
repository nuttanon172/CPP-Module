#include "easyfind.hpp"

void test1()
{
	try{
		std::cout << "---------------- Test 1 ----------------" << std::endl;
		std::vector<int> numbers;
		for (int i = 1;i<=5;i++)
			numbers.push_back(i);
		easyfind(numbers, 5);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void test2()
{
	try {
		std::cout << "---------------- Test 2 ----------------" << std::endl;
		std::vector<int> numbers;
		for (int i = 1;i<=5;i++)
			numbers.push_back(i);
		easyfind(numbers, 6);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}	
}

int main()
{
	test1();
	test2();
}
