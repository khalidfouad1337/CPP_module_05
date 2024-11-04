/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:00:50 by khalid            #+#    #+#             */
/*   Updated: 2024/11/04 15:01:55 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"


class PresidentialPardonForm : public AForm
{
    private :
        const std::string target;
        
    public :
        PresidentialPardonForm();
        
        PresidentialPardonForm(const std::string &target);
        
        ~PresidentialPardonForm();
        
        PresidentialPardonForm	&operator=(const PresidentialPardonForm &PresidentialPardonForm);
        const std::string getTarget() const;
        void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm &PresidentialPardonForm);

#endif