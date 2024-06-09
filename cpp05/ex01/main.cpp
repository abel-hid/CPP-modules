/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */ 
/*   Created: 2023/11/17 20:41:31 by abel-hid          #+#    #+#             */
/*   Updated: 2023/11/19 18:35:08 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
   try
   {
         Bureaucrat b("bureaucrat", 1);
         Form f("form", 1);
         b.signForm(f);
   }
   catch(const std::exception& e)
   {
         std::cerr << e.what() << '\n';
   }
   
    return (0);
}