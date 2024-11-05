/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:32:03 by khalid            #+#    #+#             */
/*   Updated: 2024/11/05 19:54:54 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ShrubberyCreationForm) {
    *this = ShrubberyCreationForm;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ShrubberyCreationForm) {
    if (this == &ShrubberyCreationForm) {
        return *this;
    }
    return *this;
}

const std::string ShrubberyCreationForm::getTarget() const {
    return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > getGradeToExecute()) {
        throw Bureaucrat::GradeTooLowException();
    }
    std::ofstream file(target + "_shrubbery");
    file << "       _-_\n"
            "    /~~   ~~\\\n"
            " /~~         ~~\\\n"
            "{               }\n"
            " \\  _-     -_  /\n"
            "   ~  \\\\ //  ~\n"
            "_- -   | | _- _\n"
            "  _ -  | |   -_\n"
            "      // \\\\";

    file.close();
}


std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm &ShrubberyCreationForm) {
    out << "Name: " << ShrubberyCreationForm.getName() << std::endl;
    out << "Is signed: " << ShrubberyCreationForm.getIsSigned() << std::endl;
    out << "Grade to sign: " << ShrubberyCreationForm.getGradeToSign() << std::endl;
    out << "Grade to execute: " << ShrubberyCreationForm.getGradeToExecute() << std::endl;
    return out;
}