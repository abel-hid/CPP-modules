/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:03:41 by abel-hid          #+#    #+#             */
/*   Updated: 2023/12/16 03:05:09 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm() : name("default"), Signed(false), grade_to_sign(0), grade_to_execute(0)
{
}

AForm::AForm(std::string const name, int const grade_to_sign, int const grade_to_execute) : name(name), grade_to_sign(grade_to_sign) , grade_to_execute(grade_to_execute)
{
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw AForm::GradeTooHighException();
    else if (grade_to_sign > 150 || grade_to_execute > 150)
        throw AForm::GradeTooLowException();
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.get_grade() > this->grade_to_sign)
    {
        throw AForm::GradeTooLowException();
    }
    else
        this->Signed = true;
}

AForm::AForm(AForm const &Aform) : name(Aform.name), grade_to_sign(Aform.grade_to_sign), grade_to_execute(Aform.grade_to_execute)
{
}

AForm &AForm::operator=(AForm const &AForm)
{
    this->Signed = AForm.Signed;
    return (*this);
}

AForm::~AForm()
{
    
}

std::string AForm::get_name() const
{
    return (this->name);
}

bool AForm::get_Signed() const
{
    return (this->Signed);
}

int AForm::get_grade_to_sign() const
{
    return (this->grade_to_sign);
}

int AForm::get_grade_to_execute() const
{
    return (this->grade_to_execute);
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
    out << "Form name: " << form.get_name() << std::endl;
    out << "Form grade to sign: " << form.get_grade_to_sign() << std::endl;
    out << "Form grade to execute: " << form.get_grade_to_execute() << std::endl;
    out << "Form is signed: " << form.get_Signed() << std::endl;
    return (out);
}

