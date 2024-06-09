/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 03:51:09 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/27 12:00:55 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP


#include <iostream>

class Fixed
{
    private:
        int                 fixed_point_value;
        static const int    fractional_bits = 8;
    public:
        Fixed();
        Fixed(Fixed const &fixed);
        ~Fixed();
        Fixed &operator=(Fixed const &fixed);
        int getRawBits(void) const;
        void setRawBits(int  raw);
};

#endif