/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:52:30 by abel-hid          #+#    #+#             */
/*   Updated: 2023/11/07 01:51:26 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Constructor Called" << std::endl;
}
Brain::~Brain()
{
    std::cout << "Brain Destructor Called" << std::endl;
}
Brain::Brain(Brain const &brain)
{
    std::cout << "Brain Copy Constructor Called" << std::endl;
    *this = brain;
}
Brain &Brain::operator=(Brain const &brain)
{
    std::cout << "Brain assignment operator Called" << std::endl;
    if(this != &brain)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = brain.ideas[i];
    }
    return (*this);
}