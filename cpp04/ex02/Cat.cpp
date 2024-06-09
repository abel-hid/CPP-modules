/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:04:23 by abel-hid          #+#    #+#             */
/*   Updated: 2023/11/07 01:44:23 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Constructor Called" << std::endl;
    this->brain = new Brain();
    if(this->brain == NULL)
    {
        std::cout << "Error: Memory allocation failed." << std::endl;
        exit(1);
    }
}
Cat::~Cat()
{
    delete this->brain;
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
        this->brain = new Brain(*cat.brain);
        if(this->brain == NULL)
        {
            std::cout << "Error: Memory allocation failed." << std::endl;
            exit(1);
        }
    }
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "the cat says: Meow Meow" << std::endl;
}
