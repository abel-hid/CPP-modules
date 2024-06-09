/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:41:31 by abel-hid          #+#    #+#             */
/*   Updated: 2024/01/16 19:59:50 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("a", 1);
        std::cout << a << std::endl;
        a.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        Bureaucrat b("b", 150);
        std::cout << b << std::endl;
        b.decrementGrade();
    }
    catch(std::exception &g)
    {
        std::cerr << g.what() << "\n";
    }

    return (0);
}
