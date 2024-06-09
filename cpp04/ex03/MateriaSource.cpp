/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:31:13 by abel-hid          #+#    #+#             */
/*   Updated: 2023/11/07 00:41:41 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->Materia[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
    {
        if (this->Materia[i] != NULL)
            delete this->Materia[i];
    }
}
MateriaSource::MateriaSource(MateriaSource const &materiaSource)
{
    *this = materiaSource;
}
MateriaSource &MateriaSource::operator=(MateriaSource const &materiaSource)
{
    if (this != &materiaSource)
    {
        for (int i = 0; i < 4; i++)
        {
            this->Materia[i] = materiaSource.Materia[i]->clone();
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->Materia[i] == NULL)
        {
            this->Materia[i] = materia;
            break;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->Materia[i] != NULL && this->Materia[i]->getType() == type)
            return this->Materia[i]->clone();
    }
    return NULL;
}