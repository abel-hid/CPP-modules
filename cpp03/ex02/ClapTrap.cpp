/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:31:34 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/30 13:38:54 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string Name)
{
    std::cout << "ClapTrap constructor called" << std::endl;
    this->Name = Name;
    this->Hit_points = 10;
    this->Energy_points = 10;
    this->Attack_damage = 0;
}
ClapTrap::ClapTrap(void)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &ClapTrap)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = ClapTrap;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &ClapTrap)
{
    std::cout << "ClapTrap Assignation operator called" << std::endl;
    this->Name = ClapTrap.Name;
    this->Hit_points = ClapTrap.Hit_points;
    this->Energy_points = ClapTrap.Energy_points;
    this->Attack_damage = ClapTrap.Attack_damage;
    return (*this);
}
ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}
void ClapTrap::attack(std::string const &target)
{
    if(this->Hit_points <= 0)
    {
        std::cout << "ClapTrap " << this->Name << " is dead and cannot attack!" << std::endl;
        return ;
    }
    
    if(this->Energy_points > 0 && this->Hit_points > 0)
    {
        this->Energy_points -= 1;
        std::cout << "ClapTrap " << this->Name << " attack " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->Name << " is out of energy and cannot attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->Hit_points - amount <= 0)
    {
        std::cout << "ClapTrap " << this->Name << " is dead!" << std::endl;
        this->Hit_points = 0;
    }
    std::cout << "ClapTrap " << this->Name << " take " << amount << " points of damage!" << std::endl;
    this->Hit_points -= amount;
}
void ClapTrap::beRepaired(unsigned int amount) 
{
    if(this->Energy_points <= 0)
    {
        std::cout << "ClapTrap " << this->Name << " is out of energy and cannot be repaired!" << std::endl;
        return ;
    }
    if(this->Hit_points <= 0)
    {
        std::cout << "ClapTrap " << this->Name << " is dead and cannot be repaired!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->Name << " is repaired for " << amount << " hit points!" << std::endl;
    this->Hit_points += amount;
    this->Energy_points -= 1;
}
