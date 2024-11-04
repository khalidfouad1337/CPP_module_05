/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:47:25 by khalid            #+#    #+#             */
/*   Updated: 2024/11/03 15:51:09 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("khalid"), isSigned(false), gradeToSign(1), gradeToExecute(1) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

Form::~Form() {}

Form &Form::operator=(const Form &form) {
    if (this == &form) {
        return *this;
    }
    isSigned = form.isSigned;
    return *this;
}

const std::string Form::getName() {
    return name;
}

bool Form::getIsSigned() {
    return isSigned;
}

int Form::getGradeToSign() {
    return gradeToSign;
}

int Form::getGradeToExecute() {
    return gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Form &form) {
    out << "form name " << form.getName() << ", form is signed " << form.getIsSigned() << ", form grade to sign " << form.getGradeToSign() << ", form grade to execute " << form.getGradeToExecute() << std::endl;
    return out;
}

