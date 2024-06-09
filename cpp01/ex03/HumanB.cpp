/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:57:44 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/16 22:04:24 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string name)
{
    this->name = name;
    this->weapon = NULL;
}

void HumanB::attack() 
{
    if (weapon == NULL) 
        std::cout << name << " attacks with their bare hands\n";
    else 
        std::cout << name << " attacks with their " << weapon->getType() << "\n";
    
}
void HumanB::setWeapon(Weapon& weaponType) 
{
    this->weapon = &weaponType;
}
HumanB::~HumanB()
{
}