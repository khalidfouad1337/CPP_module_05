/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:27:42 by khalid            #+#    #+#             */
/*   Updated: 2024/11/13 16:14:21 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){};

Intern::Intern(const Intern &old)
{
    *this = old;
};
Intern &Intern::operator=(const Intern &old)
{
    (void)old;
    return *this;
};

AForm *Intern::makeForm(std::string nameForm, std::string target)
{
    std::string typeForms[3] = {
        "robotomy request",
        "Shrubbery request",
        "Presidential request",
    };
    AForm *tmp;
    tmp = 0;
    AForm *forms[3] = {
        new RobotomyRequestForm(target),
        new ShrubberyCreationForm(target),
        new PresidentialPardonForm(target),
    };

    for (size_t i = 0; i < 3; i++)
    {
        if (nameForm == typeForms[i])
        {
            std::cout << "Intern creates " << target << std::endl;
            tmp = forms[i];
        }
        else
            delete forms[i];
    }
    if (!tmp)
        std::cout << nameForm << ": Form doesn’t exist." << std::endl;
    return tmp;
};
Intern::~Intern(){};