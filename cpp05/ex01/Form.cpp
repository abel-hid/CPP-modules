/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:03:41 by abel-hid          #+#    #+#             */
/*   Updated: 2024/01/16 22:10:45 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), grade_to_sign(0), grade_to_execute(0)
{
}

Form::Form(std::string const name, int const grade_to_sign) : name(name), grade_to_sign(grade_to_sign) , grade_to_execute(0)
{
    if (grade_to_sign < 1)
        throw Form::GradeTooHighException();
    else if (grade_to_sign > 150)
        throw Form::GradeTooLowException();
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.get_grade() > this->grade_to_sign)
    {
        throw Form::GradeTooLowException();
    }
    else
        this->Signed = true;
}

Form::Form(Form const &form) : name(form.name), grade_to_sign(form.grade_to_sign), grade_to_execute(form.grade_to_execute)
{
}

Form &Form::operator=(Form const &Form)
{
    if(this != &Form)
        this->Signed = Form.Signed;
    return (*this);
}

Form::~Form()
{
}

std::string Form::get_name() const
{
    return (this->name);
}

bool Form::get_Signed() const
{
    return (this->Signed);
}

int Form::get_grade_to_sign() const
{
    return (this->grade_to_sign);
}

int Form::get_grade_to_execute() const
{
    return (this->grade_to_execute);
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
    out << "Form name: " << form.get_name() << std::endl;
    out << "Form grade to sign: " << form.get_grade_to_sign() << std::endl;
    out << "Form grade to execute: " << form.get_grade_to_execute() << std::endl;
    out << "Form is signed: " << form.get_Signed() << std::endl;
    return (out);
}

