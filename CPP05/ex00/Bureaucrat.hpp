#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <cstdlib>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat(void);
        Bureaucrat(const std::string &name, const int &grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat &operator=(const Bureaucrat &obj);
        const std::string &getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
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

#endif