/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:57:13 by khalid            #+#    #+#             */
/*   Updated: 2024/11/05 19:54:32 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default") {}


RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}


RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &RobotomyRequestForm) {
    *this = RobotomyRequestForm;
}


RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &RobotomyRequestForm) {
    if (this == &RobotomyRequestForm) {
        return *this;
    }
    return *this;
}


const std::string RobotomyRequestForm::getTarget() const {
    return target;
}


void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > getGradeToExecute()) {
        throw Bureaucrat::GradeTooLowException();
    }
    std::cout << "Drilling noises" << std::endl;
    if (rand() % 2 == 0) {
        std::cout << target << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << target << " has not been robotomized successfully" << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm &RobotomyRequestForm) {
    out << "Name: " << RobotomyRequestForm.getName() << std::endl;
    out << "Is signed: " << RobotomyRequestForm.getIsSigned() << std::endl;
    out << "Grade to sign: " << RobotomyRequestForm.getGradeToSign() << std::endl;
    out << "Grade to execute: " << RobotomyRequestForm.getGradeToExecute() << std::endl;
    return out;
}