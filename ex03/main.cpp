/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:03:56 by khalid            #+#    #+#             */
/*   Updated: 2024/11/04 15:45:37 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int m(void)
{
    Intern intern;


        AForm* form1 = intern.makeForm("Shrubbery creation", "fela7");
        if (form1) {
            Bureaucrat bureaucrat("ch3ayba", 1);
			form1->beSigned(bureaucrat);
			form1->execute(bureaucrat);
			delete form1;
        }
        AForm* form2 = intern.makeForm("non-existing form", "Target");
        if (form2) {
            std::cout << "Form2 created" << std::endl;
        }
    return 0;
}

int main()
{

    m();
    system("leaks Bureaucrat");
}