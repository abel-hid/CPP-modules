/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:51:28 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/28 17:11:52 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string Name) : ScavTrap(Name)
{
    std::cout << "FragTrap constructor called" << std::endl;
    this->Name = Name;
    this->Hit_points = 100;
    this->Energy_points = 100;
    this->Attack_damage = 30;
}
FragTrap::FragTrap(void)
{
    std::cout << "FragTrap Default constructor called" << std::endl;
}
FragTrap::FragTrap(FragTrap const &FragTrap)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = FragTrap;
}
FragTrap &FragTrap::operator=(FragTrap const &FragTrap)
{
    std::cout << "FragTrap Assignation operator called" << std::endl;
    this->Name = FragTrap.Name;
    this->Hit_points = FragTrap.Hit_points;
    this->Energy_points = FragTrap.Energy_points;
    this->Attack_damage = FragTrap.Attack_damage;
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << " high fives guys" << std::endl;
}