#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Unknow"), _grade(150)
{
	
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade): _name(name), _grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighExeception();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowExeception();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << _name << "(" << _grade << ")" << " is dead\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj.getName()), _grade(obj.getGrade())
{

}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (this != &obj)
	{
		_grade = obj.getGrade();
	}
	return (*this);
}

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

void	Bureaucrat::incGrade()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighExeception();
	else
		_grade -= 1;	
}

void	Bureaucrat::decGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooHighExeception();
	else
		_grade += 1;	
}

void	Bureaucrat::signForm(AForm &obj)
{
	try
	{
		obj.beSigned(*this);
		std::cout << _name << " signed " << obj.getName() << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " << obj.getName() << " because " << e.what() << ".\n";
	}
}

void	Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << ".\n";
	}
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}
