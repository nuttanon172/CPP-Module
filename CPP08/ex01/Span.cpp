#include "Span.hpp"

Span::Span(unsigned int N) : N(N)
{
}

Span::Span(const Span &obj) : N(obj.N)
{
}

Span &Span::operator=(const Span &obj)
{
	if (this != &obj)
		N = obj.N;
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int nbr)
{
	if (container.size() == N)
		throw std::overflow_error("container is full!!");
	container.push_back(nbr);
}

void Span::addNumber(std::vector<int>::const_iterator it1, std::vector<int>::const_iterator it2)
{
	if (container.size() == N)
		throw std::overflow_error("container is full!!");
	container.insert(container.end(), it1, it2);
	if (container.size() > N)
		throw std::overflow_error("container is overflow!!");
}

int Span::shortestSpan()
{
	if (container.size() < 2)
		throw std::out_of_range("container is out of range!!");
	int tmp = abs(container[0] - container[1]);
	for (std::vector<int>::size_type i = 0; i < container.size(); i++)
	{
		for (std::vector<int>::size_type j = 1 + i; j <= container.size() - 1; j++)
		{
			if (abs(container[i] - container[j]) < tmp)
				tmp = abs(container[i] - container[j]);
		}
	}
	return (tmp);
}

int Span::longestSpan()
{
	if (container.size() < 2)
		throw std::out_of_range("container is out of range!!");
	std::vector<int>::const_iterator max_it = std::max_element(container.begin(), container.end());
	std::vector<int>::const_iterator min_it = std::min_element(container.begin(), container.end());
	return (*max_it - *min_it);
}

void Span::printContainer()
{
	for (std::vector<int>::size_type it = 0; it < container.size(); it++)
		std::cout << container[it] << ' ';
	std::cout << std::endl;
}
