#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, const int &grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat &operator=(const Bureaucrat &obj);
        const std::string &getName() const;
        int getGrade() const;
        void incGrade();
        void decGrade();
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

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
