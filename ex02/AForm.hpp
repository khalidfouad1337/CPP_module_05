#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
class Bureaucrat;
class AForm
{
    private :
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
        
    public :
        AForm();
        
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        
        ~AForm();

        AForm(const AForm &AForm);
        
        AForm	&operator=(const AForm &AForm);
        const std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

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
        virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, AForm &AForm);

#endif