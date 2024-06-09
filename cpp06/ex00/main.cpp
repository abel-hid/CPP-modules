/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:40:38 by abel-hid          #+#    #+#             */
/*   Updated: 2024/02/04 18:10:32 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

int main(int ac , char **av)
{
    if (ac == 2)
    {
        ScalarConverter::convert(av[1]);
    }
    else
        std::cerr << "Error" << std::endl;
    return (0);
}