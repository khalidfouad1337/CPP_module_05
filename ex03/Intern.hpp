/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:13:16 by khalid            #+#    #+#             */
/*   Updated: 2024/11/05 19:56:25 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


class Intern
{

    public :
        Intern();

        
        Intern(const Intern &intern);
        
        ~Intern();

        Intern(const Intern &intern);
        
        Intern	&operator=(const Intern &intern);
        
        AForm *makeForm(const std::string &form, const std::string &target);
    private :
        AForm *createShrubberyCreationForm(const std::string &target);
        AForm *createPresidentialPardonForm(const std::string &target);
        AForm *createRobotomyRequestForm(const std::string &target);
};

#endif