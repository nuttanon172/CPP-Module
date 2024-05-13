#include "AForm.hpp"

AForm::AForm() : _name("Unknow"), _sign(false), _sign_grade(150), _exec_grade(150)
{

}

AForm::AForm(const std::string &name, const int &req, const int &exec) : _name(name), _sign_grade(req), _exec_grade(exec)
{
	if (_sign_grade < 1 || _exec_grade < 1)
		throw AForm::GradeTooHighExeception();
	else if (_sign_grade > 150 || _exec_grade > 150)
		throw AForm::GradeTooLowExeception();
	_sign = false;
}

AForm::~AForm()
{
	std::cout << _name << ": has destroyed\n";
}

AForm::AForm(const AForm &obj) : _name(obj.getName()), _sign_grade(obj.getReq()), _exec_grade(obj.getExec())
{
	*this = obj;
}

AForm &AForm::operator=(const AForm &obj)
{
	if (this != &obj)
	{
		_sign = obj.getSigned();
	}
	return (*this);
}

void AForm::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() <= _sign_grade)
		_sign = true;
	else
		throw AForm::GradeTooLowExeception();
}

const std::string	&AForm::getName() const
{
	return (_name);
}

bool	AForm::getSigned() const
{
	return (_sign);
}

const int	&AForm::getReq() const
{
	return (_sign_grade);
}

const int	&AForm::getExec() const
{
	return (_exec_grade);
}

const char* AForm::NoSignedExeception::what() const throw()
{
	return ("Form is not Signed");
}

const char* AForm::GradeTooHighExeception::what() const throw()
{
	return ("Grade Too High");
}

const char* AForm::GradeTooLowExeception::what() const throw()
{
	return ("Grade Too Low");
}

std::ostream&	operator<<(std::ostream& os, const AForm& obj)
{
	os << obj.getName();
	os << ", Sign status: " << std::boolalpha << obj.getSigned();
	os << ", Grade to sign: " << obj.getReq();
	os << ", Grade to execute: " << obj.getExec() << '.';
	return (os);
}
