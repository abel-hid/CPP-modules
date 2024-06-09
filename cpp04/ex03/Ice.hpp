/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:32:25 by abel-hid          #+#    #+#             */
/*   Updated: 2023/11/02 22:24:51 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ICE_HPP
# define ICE_HPP


#include "AMateria.hpp"
class Ice : public AMateria
{
public:
    Ice();
    Ice(Ice const &ice);
    Ice &operator=(Ice const &ice);
    virtual ~Ice();
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif