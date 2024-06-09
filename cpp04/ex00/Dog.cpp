/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:10:39 by abel-hid          #+#    #+#             */
/*   Updated: 2023/11/07 01:52:00 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog Constructor Called" << std::endl;
}
Dog::~Dog()
{
    std::cout << "Dog Destructor Called" << std::endl;
}
Dog::Dog(Dog const &dog)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
    *this = dog;
}
Dog &Dog::operator=(Dog const &dog)
{
    std::cout << "Dog assignment operator Called" << std::endl;
    if(this != &dog)
    {
        this->type = dog.getType();
    }
    return (*this);
}
void Dog::makeSound() const
{
    std::cout << "the dog says: Woof Woof" << std::endl;
}
