/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:31:47 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/28 11:21:08 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap FragTrap1("FragTrap1");
    FragTrap FragTrap2("FragTrap2");
    
    FragTrap1.attack("FragTrap2");
    FragTrap2.takeDamage(5);
    FragTrap2.beRepaired(3);
    FragTrap1.highFivesGuys();
    return (0);
}
