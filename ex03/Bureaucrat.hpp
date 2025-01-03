/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 00:57:31 by khalid            #+#    #+#             */
/*   Updated: 2024/11/10 19:49:05 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class Bureaucrat
{
    private :
        const std::string name;
        int grade;
        
    public :
        Bureaucrat();
        
        Bureaucrat(const std::string name, int grade);
        
        ~Bureaucrat();

        Bureaucrat(const Bureaucrat &bureaucrat);
        
        Bureaucrat	&operator=(const Bureaucrat &bureaucrat);
        const std::string getName() const;
        int getGrade() const;
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

        void executeForm(AForm const & form);

        void signForm(AForm &Aform);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat);

#endif