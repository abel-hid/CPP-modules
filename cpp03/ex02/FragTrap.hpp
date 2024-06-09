/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:28:06 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/28 17:11:07 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ScavTrap
{
    public:
        FragTrap(void);
        FragTrap(FragTrap const &FragTrap);
        FragTrap &operator=(FragTrap const &FragTrap);
        FragTrap(std::string Name);
        ~FragTrap(void);
        void highFivesGuys(void);
};


#endif