#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _sign;
	const int _sign_grade;
	const int _exec_grade;

public:
	Form();
	Form(const std::string &name, const int &sign_grade, const int &exec_grade);
	~Form();
	Form(const Form &obj);
	Form &operator=(const Form &obj);
	void beSigned(const Bureaucrat &obj);
	const std::string &getName() const;
	bool getSigned() const;
	const int &getReq() const;
	const int &getExec() const;
	class GradeTooHighExeception : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowExeception : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif
