#include "Span.hpp"

void test1();
void test2();
void test3();
void test4();

int main()
{
	test4();
	test1();
	test2();
	test3();
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
	std::cout << "----------- 10K Numbers Test -----------" << std::endl;
	try {
		/* Create random number container */
		std::srand(std::time(0));
		std::vector<int> tmpVec(10000);
		std::generate(tmpVec.begin(), tmpVec.end(), std::rand);

		Span sp(tmpVec.size());
		sp.addNumber(tmpVec.begin(), tmpVec.end());
		sp.printContainer();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}
