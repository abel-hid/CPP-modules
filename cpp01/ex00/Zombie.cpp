/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:07:06 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/09 19:46:05 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << name << " is created" << std::endl;
}

Zombie* newZombie(std::string name)
{
    Zombie *zombie = new Zombie(name);
    return (zombie);
}

void randomChump(std::string name) 
{
    Zombie zombie(name);
    zombie.announce();
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

 void    Zombie::set_name(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed" << std::endl;
}