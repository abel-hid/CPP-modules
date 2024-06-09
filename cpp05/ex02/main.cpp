/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */ 
/*   Created: 2023/11/17 20:41:31 by abel-hid          #+#    #+#             */
/*   Updated: 2023/11/19 18:35:08 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
   try
   {
      Bureaucrat bureaucrat("b", 1);
      ShrubberyCreationForm CreationForm("target");
      std::cout << CreationForm << std::endl;
      bureaucrat.signForm(CreationForm);
      bureaucrat.executeForm(CreationForm);

      std::cout << std::endl;

      RobotomyRequestForm RequestForm("target");
      std::cout << RequestForm << std::endl;
      bureaucrat.signForm(RequestForm);
      bureaucrat.executeForm(RequestForm);

      std::cout << std::endl;

      PresidentialPardonForm PardonForm("target");
      std::cout << PardonForm << std::endl;
      bureaucrat.signForm(PardonForm);
      bureaucrat.executeForm(PardonForm);
   }
   catch(const std::exception& e)
   {
         std::cerr << e.what() << '\n';
   }
    return (0);
}  