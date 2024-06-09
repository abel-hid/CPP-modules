/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:25:52 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/17 05:55:09 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) 
{
    Zombie* zombie = new Zombie[N];
    for (int i = 0; i < N; ++i) 
    {
        zombie[i].set_name(name);
    }
    return (zombie);
}