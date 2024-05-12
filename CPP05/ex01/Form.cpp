#include "Form.hpp"

Form::Form() : _name("Unknow"), _sign(false), _sign_grade(150), _exec_grade(150)
{

}

Form::Form(const std::string &name, const int &req, const int &exec) : _name(name), _sign_grade(req), _exec_grade(exec)
{
	if (_sign_grade < 1 || _exec_grade < 1)
		throw Form::GradeTooHighExeception();
	else if (_sign_grade > 150 || _exec_grade > 150)
		throw Form::GradeTooLowExeception();
	_sign = false;
}

Form::~Form()
{
	std::cout << _name << ": has destroyed\n";
}

Form::Form(const Form &obj) : _name(obj.getName()), _sign_grade(obj.getReq()), _exec_grade(obj.getExec())
{
	*this = obj;
}

Form &Form::operator=(const Form &obj)
{
	if (this != &obj)
	{
		_sign = obj.getSigned();
	}
	return (*this);
}

void Form::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() <= _sign_grade)
		_sign = true;
	else
		throw Form::GradeTooLowExeception();
}

const std::string	&Form::getName() const
{
	return (_name);
}

bool	Form::getSigned() const
{
	return (_sign);
}

const int	&Form::getReq() const
{
	return (_sign_grade);
}

const int	&Form::getExec() const
{
	return (_exec_grade);
}

const char* Form::GradeTooHighExeception::what() const throw()
{
	return ("Grade Too High");
}

const char* Form::GradeTooLowExeception::what() const throw()
{
	return ("Grade Too Low");
}

std::ostream&	operator<<(std::ostream& os, const Form& obj)
{
	os << obj.getName();
	os << ", Sign status: " << std::boolalpha << obj.getSigned();
	os << ", Grade to sign: " << obj.getReq();
	os << ", Grade to execute: " << obj.getExec() << '.';
	return (os);
}
