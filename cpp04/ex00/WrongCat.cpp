/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:13:59 by abel-hid          #+#    #+#             */
/*   Updated: 2023/11/07 01:46:47 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat Constructor Called" << std::endl;
}
WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor Called" << std::endl;
}
WrongCat::WrongCat(WrongCat const &wrongcat)
{
    std::cout << "WrongCat Copy Constructor Called" << std::endl;
    *this = wrongcat;
}
WrongCat &WrongCat::operator=(WrongCat const &wrongcat)
{
    std::cout << "WrongCat assignment operator Called" << std::endl;
    if(this != &wrongcat)
    {
        this->type = wrongcat.getType();
    }
    return (*this);
}
void WrongCat::makeSound() const
{
    std::cout << "the WrongCat makes a sound" << std::endl;
}