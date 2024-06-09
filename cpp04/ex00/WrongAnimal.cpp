/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:12:24 by abel-hid          #+#    #+#             */
/*   Updated: 2023/11/07 01:46:22 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Constructor Called" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor Called" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal const &wronganimal)
{
    std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
    *this = wronganimal;
}
WrongAnimal &WrongAnimal::operator=(WrongAnimal const &wronganimal)
{
    std::cout << "WrongAnimal assignment operator Called" << std::endl;
    if(this != &wronganimal)
    {
        this->type = wronganimal.getType();
    }
    return (*this);
}
std::string WrongAnimal::getType() const
{
    return (this->type);
}
void WrongAnimal::makeSound() const
{
    std::cout << "the WrongAnimal makes a sound" << std::endl;
}
