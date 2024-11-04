/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:27:42 by khalid            #+#    #+#             */
/*   Updated: 2024/11/04 15:44:07 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    *this = other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::createShrubberyCreationForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &form, const std::string &target) {
    std::string forms[3] = {
        "Shrubbery creation",
        "Presidential Pardon",
        "robotomy request"
    };

    AForm *(Intern::*FormCreationFunc[3])(const std::string &target) = {
        &Intern::createShrubberyCreationForm,
        &Intern::createPresidentialPardonForm,
        &Intern::createRobotomyRequestForm
    };

    for (int i = 0; i < 3; i++) {
        if (form == forms[i]) {
            std::cout << "Intern creates " << form << std::endl;
            return (this->*FormCreationFunc[i])(target);
        }
    }
    std::cout << "Form not found" << std::endl;
    return NULL;
}