#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		~PresidentialPardonForm(void);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &obj);
		void execute(const Bureaucrat &executor) const;
};

#endif
