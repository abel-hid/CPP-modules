/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 08:19:34 by abel-hid          #+#    #+#             */
/*   Updated: 2024/01/16 22:38:07 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    
}
RobotomyRequestForm::~RobotomyRequestForm()
{
    
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45)
{
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &R)
{
    *this = R;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &R)
{
    if(this != &R)
    {
    this->target = R.target;
    }
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (executor.get_grade() > this->get_grade_to_execute())
        throw AForm::GradeTooLowException();
    if (std::rand() % 2 == 0)
        std::cout << this->target << " has been robotomized successfully 50% of the time" << std::endl;
    else
        std::cout << this->target << " has been robotomized failure 50% of the time" << std::endl;
}