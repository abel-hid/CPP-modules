/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:26:43 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/16 22:14:40 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac , char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./harl [debug, info, warning, error]" << std::endl;
        return (1);
    }
    Harl harl;
    harl.complain(av[1]);
    return (0);
}