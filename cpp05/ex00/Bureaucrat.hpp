/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:14:04 by abel-hid          #+#    #+#             */
/*   Updated: 2023/12/17 00:02:10 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        std::string const name;
        int grade;
    public:
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const &Bureaucrat);
        Bureaucrat &operator=(Bureaucrat const &Bureaucrat);
        ~Bureaucrat();
        std::string const get_name() const;
        int get_grade() const;
        void incrementGrade();
        void decrementGrade();
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

std::ostream &operator<<(std::ostream &out, Bureaucrat const &Bureaucrat);

#endif 