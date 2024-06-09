/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:27:48 by abel-hid          #+#    #+#             */
/*   Updated: 2023/11/23 21:02:48 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP


#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
    private:
        std::string const name;
        bool Signed;
        int const grade_to_sign;
        int const grade_to_execute;
    public:
        AForm();
        AForm(std::string const name, int const grade_to_sign, int const grade_to_execute);
        AForm(AForm const &Aform);
        AForm &operator=(AForm const &Aform);
        ~AForm();
        std::string get_name() const;
        bool get_Signed() const;
        int get_grade_to_sign() const;
        int get_grade_to_execute() const;
        void beSigned(Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;
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

std::ostream& operator<<(std::ostream &out ,AForm const &Aform);

#endif
