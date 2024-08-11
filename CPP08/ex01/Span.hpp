#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class Span{
private:
	unsigned int N;
	std::vector<int> container;
public:
	Span(unsigned int N);
	Span(const Span &obj);
	Span &operator=(const Span &obj);
	~Span();
	void addNumber(int nbr);
	void addNumber(std::vector<int>::const_iterator it1, std::vector<int>::const_iterator it2);
	int shortestSpan();
	int longestSpan();
	void printContainer();
};

#endif
