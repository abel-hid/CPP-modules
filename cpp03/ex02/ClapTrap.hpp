/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:31:42 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/28 17:06:37 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP


# include <iostream>
# include <string>

class ClapTrap
{
    protected:
        std::string Name;
        int Hit_points;
        int Energy_points;
        int Attack_damage;
    public:
        ClapTrap(std::string Name);
        ~ClapTrap(void);
        ClapTrap(void);
        ClapTrap(ClapTrap const &ClapTrap);
        ClapTrap &operator=(ClapTrap const &ClapTrap);
        void attack(std::string const &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};



#endif