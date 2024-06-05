#include "Array.hpp"

int main()
{
	Array<int> A(20);

	for (int i = 0; i < 20; i++)
	{
		A[i] = i;
	}
	for (int i = 0; i < 20; i++)
		std::cout << "A[" << i << "]: "  << A[i] << std::endl;
}
