/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:04:23 by abel-hid          #+#    #+#             */
/*   Updated: 2023/11/07 01:44:54 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat Constructor Called" << std::endl;
}
Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;
}
Cat::Cat(Cat const &cat)
{
    std::cout << "Cat Copy Constructor Called" << std::endl;
    *this = cat;
}
Cat &Cat::operator=(Cat const &cat)
{
    std::cout << "Cat assignment operator Called" << std::endl;
    if(this != &cat)
    {
        this->type = cat.getType();
    }
    return (*this);
}
void Cat::makeSound() const
{
    std::cout << "the cat says: Meow Meow" << std::endl;
}

