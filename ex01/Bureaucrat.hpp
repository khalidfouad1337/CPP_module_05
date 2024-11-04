/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 00:57:31 by khalid            #+#    #+#             */
/*   Updated: 2024/11/04 19:03:04 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Bureaucrat
{
    private :
        const std::string name;
        int grade;
        
    public :
        Bureaucrat();
        
        Bureaucrat(const std::string &name, int grade);
        
        ~Bureaucrat();
        
        Bureaucrat	&operator=(const Bureaucrat &bureaucrat);
        const std::string getName();
        int getGrade();
        void add();
        void sub();
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat);

#endif