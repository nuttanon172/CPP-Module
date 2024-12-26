#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &obj)
{
	*this = obj;
}

RPN &RPN::operator=(const RPN &obj)
{
	if (this != &obj)
	{
		st = obj.st;
	}
	return *this;
}

RPN::~RPN() {}

int RPN::execute(int &front, int &back, char op)
{
	switch (op)
	{
	case '+':
		return front + back;
	case '-':
		return front - back;
	case '*':
		return front * back;
	case '/':
		return !back ? throw std::invalid_argument("undefined") : front / back;
	default:
		break;
	}
	return 0;
}

void RPN::calculate(std::string arg)
{
	int front;
	int back;
	bool space(true);

	try
	{
		for (size_t i = 0; arg[i]; i++)
		{
			if (arg[i] == ' ' && !space && arg[i + 1])
			{
				space = true;
				continue;
			}
			else if (isdigit(arg[i]) && space)
			{
				st.push(arg[i] - '0');
			}
			else if ((arg[i] == '+' || arg[i] == '-' || arg[i] == '*' || arg[i] == '/') && st.size() > 1 && space)
			{
				back = st.top();
				st.pop();
				front = st.top();
				st.pop();
				st.push(execute(front, back, arg[i]));
			}
			else
			{
				std::cerr << "Error: invalid" << std::endl;
				return;
			}
			space = false;
		}
		if (st.size() != 1)
		{
			std::cerr << "Error: invalid" << std::endl;
			return;
		}
		else
			std::cout << st.top() << std::endl;
	}
	catch (std::invalid_argument &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}