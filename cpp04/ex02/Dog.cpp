/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:10:39 by abel-hid          #+#    #+#             */
/*   Updated: 2023/11/07 01:52:48 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Constructor Called" << std::endl;
    this->brain = new Brain();
    if(this->brain == NULL)
    {
        std::cout << "Error: Memory allocation failed." << std::endl;
        exit(1);
    }
}
Dog::~Dog()
{
    delete this->brain;
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
        this->brain = new Brain(*dog.brain);
        if(this->brain == NULL)
        {
            std::cout << "Error: Memory allocation failed." << std::endl;
            exit(1);
        }
    }
    return (*this);
}
 
void Dog::makeSound() const
{
    std::cout << "the dog says: Woof Woof" << std::endl;
}
