/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:27:28 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/17 06:28:39 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>


class Harl
{
    private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    public:
    
    int get_index(std::string level);
    void complain( std::string level);
};

#endif