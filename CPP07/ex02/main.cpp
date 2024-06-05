#include "Array.hpp"
#include <stdio.h>
int main()
{
	Array<int> A(20);

	try{
		for (int i = 0; i < 20; i++){
			A[i] = i;
			std::cout << "A[" << i << "]: "  << A[i] << std::endl;
		}
		Array<int> B(A);
		for (int i = 0; i < 20; i++)
			std::cout << "B[" << i << "]: "  << B[i] << std::endl;
		Array<int> C;
		for (int i = 0; i < 20; i++)
			B[i] = 1;
		A = B;
		for (int i = 0; i < 20; i++)
			std::cout << "A[" << i << "]: "  << A[i] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
