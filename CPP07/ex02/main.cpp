#include "Array.hpp"

int main()
{
	try
	{
		Array<int> A(10);
		Array<std::string> st;
		for (int i = 0; i < 10; i++)
		{
			A[i] = i;
			std::cout << "A[" << i << "]: " << A[i] << " ";
		}
		std::cout << std::endl;

		Array<int> B(A);
		for (int i = 0; i < 10; i++)
			std::cout << "B[" << i << "]: " << B[i] << " ";
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			B[i] = 1;
		A = B;
		for (int i = 0; i < 10; i++)
			std::cout << "A[" << i << "]: " << A[i] << " ";
		std::cout << std::endl;
		A[10];
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
