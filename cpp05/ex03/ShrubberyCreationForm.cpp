/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 08:25:00 by abel-hid          #+#    #+#             */
/*   Updated: 2023/12/17 08:28:36 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &S)
{
    *this = S;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &S)
{
    this->target = S.target;
    return (*this);
}

std::string ShrubberyCreationForm::get_target() const
{
    return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.get_grade() > this->get_grade_to_execute())
        throw AForm::GradeTooLowException();
        
    std::ofstream outfile(get_target() + "_shrubbery");
    if (outfile.is_open())
    {
        outfile << "    oxoxoo    ooxoo" << std::endl;
        outfile << "  ooxoxo oo  oxoxooo" << std::endl;
        outfile << " oooo xxoxoo ooo ooox" << std::endl;
        outfile << " oxo o oxoxo  xoxxoxo" << std::endl;
        outfile << "  oxo xooxoooo o ooo" << std::endl;
        outfile << "    ooo\\oo\\  /o/o" << std::endl;
        outfile << "        \\  \\/ /" << std::endl;
        outfile << "         |   /" << std::endl;
        outfile << "         |  |" << std::endl;
        outfile << "         | D|" << std::endl;
        outfile << "         |  |" << std::endl;
        outfile << "         |  |" << std::endl;
        outfile << "  ______/____\\____" << std::endl;
        outfile.close();
    }
    else
    {
        std::cout << "Error: could not open file" << std::endl;
    }
}