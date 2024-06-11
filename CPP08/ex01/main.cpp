#include "Span.hpp"

void test1();
void test2();
void test3();
void test4();

int main()
{
	test1();
	test2();
	test3();
	test4();
}

void test1()
{
	std::cout << "---------------- Test 1 ----------------" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.printContainer();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}

void test2()
{
	std::cout << "---------------- Test 2 ----------------" << std::endl;
	try {
		Span sp = Span(4);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}

void test3()
{
	std::cout << "---------------- Test 3 ----------------" << std::endl;
	try {
		std::srand(std::time(0));
		Span sp = Span(10);
		for (int i =0;i < 10;i++)
			sp.addNumber(std::rand() % 1000);
		sp.printContainer();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}

void test4()
{
	std::cout << "---------------- Test 4 ----------------" << std::endl;
	try {
		//addNumber 10k
		Span sp = Span(10000);
		for (int i = 1;i <= 10000;i++)
			sp.addNumber(i);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}
