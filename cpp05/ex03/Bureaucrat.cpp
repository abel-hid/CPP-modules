/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:59:21 by abel-hid          #+#    #+#             */
/*   Updated: 2023/12/16 03:09:47 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(std::string const Name, int Grade) : Name(Name), Grade(Grade)
{
    if (Grade < 1)
        throw GradeTooHighException();
    else if (Grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &Bureaucrat)
{
    *this = Bureaucrat;
}
Bureaucrat& Bureaucrat::operator=(Bureaucrat const &Bureaucrat)
{
    if(this != &Bureaucrat)
        this->Grade = Bureaucrat.get_grade();
    return (*this);
}
Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->Name << " signs " << form.get_name() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->Name << " couldn’t sign " << form.get_name() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::incrementGrade()
{
    if (this->Grade == 1)
        throw GradeTooHighException();
    this->Grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->Grade == 150)
        throw GradeTooLowException();
    this->Grade++;
}
std::string const Bureaucrat::get_name() const
{
    return (this->Name);
}

int Bureaucrat::get_grade() const
{
    return (this->Grade);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &Bureaucrat)
{
    out << Bureaucrat.get_name() << ", bureaucrat grade " << Bureaucrat.get_grade() << std::endl;
    return (out);
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->Name << " executes " << form.get_name() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Execution failed: " << e.what() << std::endl;
    }
}