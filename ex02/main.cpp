/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:03:56 by khalid            #+#    #+#             */
/*   Updated: 2024/11/04 15:11:16 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{

	Bureaucrat bureaucrat("John", 31);
	std::cout << bureaucrat << std::endl;


	ShrubberyCreationForm shrubberyForm("Target1");
	std::cout << shrubberyForm << std::endl;
	bureaucrat.signForm(shrubberyForm);
	bureaucrat.executeForm(shrubberyForm);

	PresidentialPardonForm presidentialForm("Target2");
	std::cout << presidentialForm << std::endl;
	bureaucrat.signForm(presidentialForm);
	bureaucrat.executeForm(presidentialForm);

	RobotomyRequestForm robotomyForm("Target3");
	std::cout << robotomyForm << std::endl;
	bureaucrat.signForm(robotomyForm);
	bureaucrat.executeForm(robotomyForm);

	return 0;
}