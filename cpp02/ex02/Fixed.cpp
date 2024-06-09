/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 05:27:54 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/26 18:11:24 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    fixed_point_value = 0;
}

Fixed::Fixed(Fixed const &fixed)
{
    *this = fixed;
}

Fixed::~Fixed()
{

}

Fixed &Fixed::operator=(Fixed const &fixed)
{
    if (this != &fixed)
    {
        this->fixed_point_value = fixed.fixed_point_value;
    }
    return *this;
}

Fixed:: Fixed(float value)
{
    this->fixed_point_value = roundf(value * (1 << fractional_bits));
}

Fixed:: Fixed(int value)
{
    this->fixed_point_value = value << fractional_bits;
}

int Fixed::toInt(void) const
{
    return (this->fixed_point_value >> fractional_bits);
}

float Fixed::toFloat(void) const
{
    return ((float)this->fixed_point_value / (1 << fractional_bits));
}

Fixed& Fixed::min(Fixed& a, Fixed& b) 
{
   if(a < b)
        return (a);
    return (b);
}
Fixed& Fixed::max(Fixed& a, Fixed& b) 
{
    if(a > b)
        return (a);
    return (b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) 
{
    if(a < b)
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) 
{
    if(a > b)
        return (a);
    return (b);
}

Fixed Fixed::operator+(Fixed const &fixed) const
{
    return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(Fixed const &fixed) const
{
    return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(Fixed const &fixed) const
{
    return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(Fixed const &fixed) const
{
    if(fixed.toFloat() == 0)
    {
        std::cout << "Error: can't divide by zero" << std::endl;
        return (Fixed(0));
    }
    return (Fixed(this->toFloat() / fixed.toFloat()));
}

int Fixed::operator>(Fixed const &fixed) const
{
    return (this->toFloat() > fixed.toFloat());
}

int Fixed::operator<(Fixed const &fixed) const
{
    return (this->toFloat() < fixed.toFloat());
}

int Fixed::operator>=(Fixed const &fixed) const
{
    return (this->toFloat() >= fixed.toFloat());
}

int Fixed::operator<=(Fixed const &fixed) const
{
    return (this->toFloat() <= fixed.toFloat());
}

int Fixed::operator==(Fixed const &fixed) const
{
    return (this->toFloat() == fixed.toFloat());
}

int Fixed::operator!=(Fixed const &fixed) const
{
    return (this->toFloat() != fixed.toFloat());
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    fixed_point_value++;
    return tmp;
}

Fixed& Fixed::operator++()
{
    this->fixed_point_value++;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    fixed_point_value--;
    return tmp;
}

Fixed& Fixed::operator--()
{
    this->fixed_point_value--;
    return *this;
}

std::ostream& operator<<(std::ostream& out_stream, const Fixed& fixed) 
{
    out_stream << fixed.toFloat();
    return (out_stream);
}
