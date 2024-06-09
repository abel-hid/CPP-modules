/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:17:47 by abel-hid          #+#    #+#             */
/*   Updated: 2023/11/04 20:40:41 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(Ice const &ice)
{
    *this = ice;
}
Ice &Ice::operator=(Ice const &ice)
{
    if (this != &ice)
    {
        this->type = ice.type;
    }
    return (*this);
}
AMateria *Ice::clone() const
{
    return (new Ice(*this));
}
void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
Ice::~Ice()
{
}