#include "Bureaucrat.hpp"
#include "Form.hpp"


Bureaucrat::Bureaucrat() : name("khalid"), grade(1) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
}


Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
    if (this == &bureaucrat) {
        return *this;
    }
    grade = bureaucrat.grade;
    return *this;
}

const std::string Bureaucrat::getName()  {
    return name;
}       
int Bureaucrat::getGrade()  {
    return grade;
}

void Bureaucrat::add() {
    if (grade <= 1) {
        throw GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::sub() {
    if (grade >= 150) {
        throw GradeTooLowException();
    }
    grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

void Bureaucrat::signForm(Form &form)
{
    try {
        if (grade > form.getGradeToSign())
            throw Bureaucrat::GradeTooLowException();
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat) {
    out << "bureaucrat name " << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return out;
}