#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequest", 72, 45), _target("Unknow")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequest", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj.getName(), obj.getReq(), obj.getExec())
{
	_target = obj._target;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	if (this != &obj)
	{
		_target = obj._target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() <= this->getExec())
	{
		if (this->getSigned() == false)
			throw AForm::NoSignedExeception();
		std::srand(std::time(0));
		if (std::rand() % 2 == 0)
			std::cout << _target << " has been robotomized successfully 50% of the time.\n";
		else
			std::cout << _target << " robotomy failed.\n";
	}
	else
		throw AForm::GradeTooLowExeception();
}
