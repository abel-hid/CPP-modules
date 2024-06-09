/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:33:21 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/31 14:39:35 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name) 
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->Name = Name;
    this->Hit_points = 100;
    this->Energy_points = 50;
    this->Attack_damage = 20;
}
ScavTrap::ScavTrap(void)
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
}
ScavTrap::ScavTrap(ScavTrap const &ScavTrap)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    *this = ScavTrap;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &ScavTrap)
{
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    this->Name = ScavTrap.Name;
    this->Hit_points = ScavTrap.Hit_points;
    this->Energy_points = ScavTrap.Energy_points;
    this->Attack_damage = ScavTrap.Attack_damage;
    return (*this);
}

void ScavTrap::attack(std::string const & target)
{
    if(this->Energy_points <= 0)
    {
        std::cout << "ScavTrap " << Name << " is out of energy" << std::endl;
        return ;
    }
    if(this->Energy_points > 0 && this->Hit_points > 0)
    {
        std::cout << "ScavTrap " << Name << " attack " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
        Energy_points -= 1;
    }
    else
        std::cout << "ScavTrap " << Name << " is dead and cannot attack!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << Name << " have enterred in Gate keeper mode" << std::endl;
}