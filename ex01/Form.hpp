#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
class Bureaucrat;

class Form
{
    private :
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
        
    public :
        Form();
        
        Form(const std::string &name, int gradeToSign, int gradeToExecute);
        
        ~Form();
        
        Form(const Form &form);
        
        Form	&operator=(const Form &form);
        const std::string getName();
        bool getIsSigned();
        int getGradeToSign();
        int getGradeToExecute();

        void beSigned(Bureaucrat &bureaucrat);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Form &form);

#endif