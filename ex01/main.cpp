/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:16:04 by kfouad            #+#    #+#             */
/*   Updated: 2024/11/04 21:41:53 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{

    try
    {
        Bureaucrat bureaucrat("fouad" ,2);
        Form form("f1", 2, 5);
        bureaucrat.signForm(form);
        std::cout << form << form;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    };
    return 0;
}