/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:16:29 by abel-hid          #+#    #+#             */
/*   Updated: 2023/12/17 01:46:19 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP


#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
    private:
        std::string const name;
        bool Signed;
        int const grade_to_sign;
        int const grade_to_execute;
    public:
        Form();
        Form(std::string const name, int const grade_to_sign);
        Form(Form const &form);
        Form &operator=(Form const &form);
        ~Form();
        std::string get_name() const;
        bool get_Signed() const;
        int get_grade_to_sign() const;
        int get_grade_to_execute() const;
        void beSigned(Bureaucrat &bureaucrat);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("grade is too high");
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("grade is too low");
                }
        };
};

std::ostream& operator<<(std::ostream &out ,Form const &form);

#endif
