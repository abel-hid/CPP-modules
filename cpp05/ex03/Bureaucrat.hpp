/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:14:04 by abel-hid          #+#    #+#             */
/*   Updated: 2023/12/16 03:09:16 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
class AForm;
class Bureaucrat
{
    private:
        std::string const Name;
        int Grade;
    public:
        Bureaucrat(std::string const Name, int Grade);
        Bureaucrat(Bureaucrat const &Bureaucrat);
        Bureaucrat &operator=(Bureaucrat const &Bureaucrat);
        ~Bureaucrat();
        std::string const get_name() const;
        int get_grade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &form);
        void executeForm(AForm const & form);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Grade too high");
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Grade too low");
                }
        };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &Bureaucrat);

#endif 