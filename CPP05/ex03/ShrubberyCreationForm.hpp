#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &obj);
		void execute(const Bureaucrat &executor) const;
};

#endif