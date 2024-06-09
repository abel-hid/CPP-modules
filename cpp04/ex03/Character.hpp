/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:20:48 by abel-hid          #+#    #+#             */
/*   Updated: 2023/11/05 01:53:11 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
    std::string Name;
    AMateria* Materia[4];

public:
    
    Character(Character const &character);
    Character &operator=(Character const &character);
    virtual ~Character();
    Character(std::string const &name);
    std::string const &getName() const;
    void equip(AMateria *materia);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};


#endif