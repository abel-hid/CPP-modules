/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 08:11:26 by abel-hid          #+#    #+#             */
/*   Updated: 2024/01/16 22:12:55 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", 25, 5)
{
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &p)
{
    *this = p;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &p)
{
    this->target = p.target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string  PresidentialPardonForm::get_target() const
{
    return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (executor.get_grade() > this->get_grade_to_execute())
        throw AForm::GradeTooLowException();
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
