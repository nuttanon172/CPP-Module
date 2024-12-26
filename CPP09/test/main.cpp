#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vect;
	size_t n = 5;
	size_t prevJacobVal = 1;
	while (prevJacobVal < n)
	{
		std::cout << "push: " << prevJacobVal << '\n';
		vect.push_back(prevJacobVal++);
	}
	std::cout << "distance: " << std::distance(vect.begin(), vect.end()) << std::endl;
	std::vector<int>::iterator it = vect.end();
	//std::advance(it, 3);
	std::cout << "it = " << *it << "\n";
    /*prevJacobVal = 1;
	for (std::vector<int>::const_iterator it = vect.begin(); it != vect.end(); it++)
	{
		prevJacobVal = *it;
		//insertSeq.push_back(*jacobVal);
		for (size_t i = *it; i > prevJacobVal + 1; i--)
			std::cout << "this loop working...";
	}*/
	//std::cout << std::distance(vect.begin(), vect.end()) << std::endl;
}