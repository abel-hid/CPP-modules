/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:31:47 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/28 11:16:28 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap ScavTrap1("ScavTrap1");
    ScavTrap ScavTrap2("ScavTrap2");
    
    ScavTrap1.attack("ScavTrap2");
    ScavTrap2.takeDamage(5);
    ScavTrap2.beRepaired(3);
    ScavTrap1.guardGate();
    return (0);
}

