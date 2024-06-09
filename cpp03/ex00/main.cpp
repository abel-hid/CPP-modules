/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 05:11:49 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/28 10:59:31 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap ClapTrap1("ClapTrap1");
    ClapTrap ClapTrap2("ClapTrap2");
    
    ClapTrap1.attack("ClapTrap2");
    ClapTrap2.takeDamage(5);
    ClapTrap2.beRepaired(3);
    return (0);
}

