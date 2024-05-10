#include "Form.hpp"

Form::Form() : _name("Unknow"), _sign(false), _req_grade(150), _exec_grade(150)
{

}

Form::Form(const std::string &name, const int &req, const int &exec) : _name(name), _req_grade(req), _exec_grade(exec)
{
	if (_req_grade > 150 || _exec_grade > 150)
		throw Form::GradeTooLowExeception();
	else if (_req_grade < 1 || _exec_grade < 1)
		throw Form::GradeTooHighExeception();
	_sign = false;
}

Form::~Form()
{
	std::cout << _name << ": has destroyed";
}

Form::Form(const Form &obj) : _name(obj.getName()), _req_grade(obj.getReq()), _exec_grade(obj.getExec())
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
	if (obj.getGrade() <= _req_grade)
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
	return (_req_grade);
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
	os << obj.getName() << ", Required grade to sign: " << obj.getReq();
	os << "\nRequired grade to execute: " << obj.getExec();
	os << "\nsign status: " << obj.getSigned();
	return (os);
}
