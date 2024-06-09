/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:54:16 by abel-hid          #+#    #+#             */
/*   Updated: 2023/12/17 08:23:18 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP


#include "AForm.hpp"

class RobotomyRequestForm : public AForm 
{

    private:
     std::string target;
        
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const &R);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &R);
        void execute(Bureaucrat const &executor) const;
    
};

#endif