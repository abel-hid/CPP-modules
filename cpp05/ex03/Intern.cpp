/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:52:04 by abel-hid          #+#    #+#             */
/*   Updated: 2024/01/16 23:17:03 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &i)
{
    *this = i;
}
Intern &Intern::operator=(Intern const &i)
{
    (void)i;
    return (*this);
}

Intern::~Intern()
{
}


AForm *Intern::makeForm(std::string const name, std::string const target)
{
    std::string const names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
    for (int i = 0; i < 3; i++)
    {
        if (name == names[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            switch(i)
            {
                case 0:
                    delete forms[1];
                    delete forms[2];
                    break;
                case 1:
                    delete forms[0];
                    delete forms[2];
                    break;
                case 2:
                    delete forms[0];
                    delete forms[1];
                    break;
            }
            return (forms[i]);
        }
    }
    std::cout << "Intern can't create " << name << " because it's not a valid form" << std::endl;
    delete forms[0];
    delete forms[1];
    delete forms[2];
    return (NULL);
}