#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Unknow"), _grade(150)
{
	
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade): _name(name), _grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighExeception();
	else if (_grade > 150)
	{	
		std::cout << "I'm in\n";
		throw Bureaucrat::GradeTooLowExeception();
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << _name << "(" << _grade << ")" << " is dead\n";
}

//Bureaucrat::Bureaucrat(const Bureaucrat &obj)
//{
//	*this = obj;
//}

//Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj);
//{
//	if (this != &obj)
//	{
//		_name = obj.getName();
//		_grade = obj.getGrade();
//	}
//	return (*this);
//}

const std::string	&Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

const char	*Bureaucrat::GradeTooHighExeception::what() const throw()
{
	return ("Grade Too High");
}

const char	*Bureaucrat::GradeTooLowExeception::what() const throw()
{
	return ("Grade Too Low");
}
