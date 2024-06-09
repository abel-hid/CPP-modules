/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:32:57 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/17 06:06:51 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int ac, char **av)
{
    if(ac == 4)
    {
        std::string file = av[1];
        std::string s1 = av[2];
        std::string s2 = av[3];
        replace(file,s1, s2);
    }
    else    
        std::cout << "Error: invalid number of arguments\n";
}