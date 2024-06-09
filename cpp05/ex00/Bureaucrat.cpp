/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:59:21 by abel-hid          #+#    #+#             */
/*   Updated: 2024/01/16 03:18:27 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &Bureaucrat)
{
    *this = Bureaucrat;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &Bureaucrat)
{
    if(this != &Bureaucrat)
        this->grade = Bureaucrat.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::incrementGrade()
{
    if (this->grade == 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade == 150)
        throw GradeTooLowException();
    this->grade++;
}

std::string const Bureaucrat::get_name() const
{
    return (this->name);
}

int Bureaucrat::get_grade() const
{
    return (this->grade);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &Bureaucrat)
{
    out << Bureaucrat.get_name() << ", bureaucrat grade " << Bureaucrat.get_grade() << std::endl;
    return (out);
}