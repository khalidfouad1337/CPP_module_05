/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:55:46 by khalid            #+#    #+#             */
/*   Updated: 2024/11/05 19:57:10 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"


class RobotomyRequestForm : public AForm
{
    private :
        const std::string target;
        
    public :
        RobotomyRequestForm();
        
        RobotomyRequestForm(const std::string &target);
        
        ~RobotomyRequestForm();

        RobotomyRequestForm(const RobotomyRequestForm &RobotomyRequestForm);
        
        RobotomyRequestForm	&operator=(const RobotomyRequestForm &RobotomyRequestForm);
        const std::string getTarget() const;
        void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm &RobotomyRequestForm);

#endif