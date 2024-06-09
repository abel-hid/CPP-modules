/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:26:14 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/17 05:57:08 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() 
{
    std::string name = "zombie";
    int N = 6;  
    Zombie* zombies = zombieHorde(N, name);

    for (int i = 0; i < N; ++i) 
    {
        zombies[i].announce();
    } 
    delete[] zombies;
    return 0;
}
