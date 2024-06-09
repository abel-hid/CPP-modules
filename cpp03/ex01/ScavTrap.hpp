/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:33:35 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/30 13:33:34 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(std::string Name);
        ~ScavTrap(void);
        ScavTrap(void);
        ScavTrap(ScavTrap const &ScavTrap);
        ScavTrap &operator=(ScavTrap const &ScavTrap);
        void guardGate(void);
        void attack(std::string const & target);
};



#endif