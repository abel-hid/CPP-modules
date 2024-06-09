/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 01:22:59 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/27 11:58:03 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point_value = 0;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixed_point_value = value << fractional_bits;
}
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixed_point_value = roundf(value * (1 << fractional_bits));
}
Fixed::Fixed(Fixed const &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed   &Fixed::operator=(Fixed const &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixed_point_value = fixed.getRawBits();
    return (*this);
}
int    Fixed::getRawBits(void) const
{
    return (this->fixed_point_value);
}
void   Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed_point_value = raw;
}
float   Fixed::toFloat(void) const
{
    return ((float)this->fixed_point_value / (1 << fractional_bits));
}
int     Fixed::toInt(void) const
{
    return (this->fixed_point_value >> fractional_bits);
}

std::ostream    &operator<<(std::ostream &out, Fixed const &fixed)
{
    out << fixed.toFloat();
    return (out);
}