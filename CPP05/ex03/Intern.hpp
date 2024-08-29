#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialParndonForm;

class Intern
{
public:
	Intern();
	Intern(const Intern &obj);
	~Intern();
	Intern &operator=(const Intern &obj);
	AForm *makeForm(const std::string &form_type, const std::string &target);
};

#endif