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
#include "Intern.hpp"

int main()
{
   {
      Intern someRandomIntern;
      AForm* rrf;
      rrf = someRandomIntern.makeForm("robotomy request", "Bender");
      delete rrf;
      AForm* ppf;
      ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
      delete ppf;
      AForm* scf;
      scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
      delete scf;
   }
   std::cout << "-------------------------------------" << std::endl;
   try
   {
      Bureaucrat b("b", 1);
      ShrubberyCreationForm s("home");
      b.signForm(s);
      b.executeForm(s);
      std::cout << "-------------------------------------" << std::endl;
      RobotomyRequestForm r("home");
      b.signForm(r);
      b.executeForm(r);
      std::cout << "-------------------------------------" << std::endl;
      PresidentialPardonForm p("home");
      b.signForm(p);
      b.executeForm(p);
   }
   catch(const std::exception& e)
   {
      std::cerr << e.what() << '\n';
   }
   return (0);
}  