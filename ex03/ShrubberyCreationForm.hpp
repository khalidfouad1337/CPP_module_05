/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:29:09 by khalid            #+#    #+#             */
/*   Updated: 2024/11/05 19:57:30 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private :
        const std::string target;
        
    public :
        ShrubberyCreationForm();
        
        ShrubberyCreationForm(const std::string &target);
        
        ~ShrubberyCreationForm();

        ShrubberyCreationForm(const ShrubberyCreationForm &ShrubberyCreationForm);
        
        ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &ShrubberyCreationForm);
        const std::string getTarget() const;
        void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm &ShrubberyCreationForm);

#endif