/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:47:25 by khalid            #+#    #+#             */
/*   Updated: 2024/11/05 20:02:24 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("khalid"), isSigned(false), gradeToSign(1), gradeToExecute(1) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

AForm::~AForm() {}

AForm::AForm(const AForm &Aform)
    : name(Aform.name), isSigned(Aform.isSigned), gradeToSign(Aform.gradeToSign), gradeToExecute(Aform.gradeToExecute) {
    // Copy constructor implementation
}

AForm &AForm::operator=(const AForm &AForm) {
    if (this == &AForm) {
        return *this;
    }
    isSigned = AForm.isSigned;
    return *this;
}

const std::string AForm::getName() const{
    return name;
}

bool AForm::getIsSigned() const{
    return isSigned;
}

int AForm::getGradeToSign() const{
    return gradeToSign;
}

int AForm::getGradeToExecute() const{
    return gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, AForm &AForm) {
    out << "form name " << AForm.getName() << ", form is signed " << AForm.getIsSigned() << ", form grade to sign " << AForm.getGradeToSign() << ", form grade to execute " << AForm.getGradeToExecute() << std::endl;
    return out;
}

