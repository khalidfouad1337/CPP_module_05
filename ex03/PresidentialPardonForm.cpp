/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:02:03 by khalid            #+#    #+#             */
/*   Updated: 2024/11/05 19:57:00 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default") {}


PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}


PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &PresidentialPardonForm) {
    *this = PresidentialPardonForm;
}


PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &PresidentialPardonForm) {
    if (this == &PresidentialPardonForm) {
        return *this;
    }
    return *this;
}


const std::string PresidentialPardonForm::getTarget() const {
    return target;
}


void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > getGradeToExecute()) {
        throw Bureaucrat::GradeTooLowException();
    }
    std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm &PresidentialPardonForm) {
    out << "Name: " << PresidentialPardonForm.getName() << std::endl;
    out << "Is signed: " << PresidentialPardonForm.getIsSigned() << std::endl;
    out << "Grade to sign: " << PresidentialPardonForm.getGradeToSign() << std::endl;
    out << "Grade to execute: " << PresidentialPardonForm.getGradeToExecute() << std::endl;
    return out;
}