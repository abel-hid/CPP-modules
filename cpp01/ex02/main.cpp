/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:42:51 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/09 14:48:42 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    
    std::cout << "The memory address of the string: " << &str << std::endl;
    std::cout << "The memory address of the stringPTR: " << stringPTR << std::endl;
    std::cout << "The memory address of the stringREF: " << &stringREF << std::endl;
    std::cout << "The value of the string: " << str << std::endl;
    std::cout << "The value of the stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value of the stringREF: " << stringREF << std::endl;
    return (0);
}