/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:16:56 by abel-hid          #+#    #+#             */
/*   Updated: 2023/11/07 02:42:54 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
    this->type = type;
}
AMateria::AMateria(AMateria const & materia)
{
    *this = materia;
}
AMateria &AMateria::operator=(AMateria const & materia)
{
    if (this != &materia)
    {
        this->type = materia.type;
    }
    return (*this);
}
AMateria::~AMateria()
{
}
std::string const & AMateria::getType() const
{
    return this->type;
}
void AMateria::use(ICharacter& target)
{
    std::cout << "* uses " << this->type << " on " << target.getName() << " *" << std::endl;
}