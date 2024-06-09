/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:01:32 by abel-hid          #+#    #+#             */
/*   Updated: 2023/11/07 01:44:20 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal Constructor Called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor Called" << std::endl;
}
Animal::Animal(std::string type)
{
    std::cout << "Animal Constructor Called" << std::endl;
    this->type = type;
}

Animal::Animal(Animal const &animal)
{
    this->type = animal.getType();
}

Animal &Animal::operator=(Animal const &animal)
{
    std::cout << "Animal assignment operator Called" << std::endl;
    if(this != &animal)
    {
        this->type = animal.getType();
    }
    return (*this);
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound() const
{
    std::cout << "the animal makes a sound" << std::endl;
}