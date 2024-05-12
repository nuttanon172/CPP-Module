#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _sign;
		const int _sign_grade;
		const int _exec_grade;
	public:
		AForm();
		AForm(const std::string &name, const int &sign_grade, const int &exec_grade);
		virtual ~AForm();
		AForm(const AForm &obj);
		AForm &operator=(const AForm &obj);
		void beSigned(const Bureaucrat &obj);
		const std::string &getName() const;
		bool getSigned() const;
		const int &getReq() const;
		const int &getExec() const;
		virtual void execute(const Bureaucrat &executor) const = 0;
	class GradeTooHighExeception : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowExeception : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream&	operator<<(std::ostream& os, const AForm& obj);

#endif
