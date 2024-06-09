/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:44:36 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/10 21:38:27 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon &weapon;
	public:
	HumanA(const std::string &name, Weapon &weapon);
		~HumanA();
		void attack(void)
		{
			std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
		}
};

#endif