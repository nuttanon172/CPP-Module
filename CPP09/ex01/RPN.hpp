#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <exception>

class RPN
{
private:
	std::stack<int> st;
	int execute(int &front, int &back, char op);

public:
	RPN();
	RPN(const RPN &obj);
	RPN &operator=(const RPN &obj);
	~RPN();
	void calculate(std::string arg);
};

#endif
