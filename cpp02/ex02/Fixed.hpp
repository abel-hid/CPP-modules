#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed 
{
private:
    int fixed_point_value;
    static const int fractional_bits = 8;

public:
    Fixed();
    Fixed(float value);
    Fixed(int value);
    Fixed(const Fixed &fixed);
    ~Fixed();
    Fixed& operator=(const Fixed &fixed);
    float toFloat(void) const;
    int toInt(void) const;
    Fixed operator+(Fixed const &fixed) const;
    Fixed operator-(Fixed const &fixed) const;
    Fixed operator*(Fixed const &fixed) const;
    Fixed operator/(Fixed const &fixed) const;
    int operator>(Fixed const &fixed) const;
    int operator<(Fixed const &fixed) const;
    int operator>=(Fixed const &fixed) const;
    int operator<=(Fixed const &fixed) const;
    int operator==(Fixed const &fixed) const;
    int operator!=(Fixed const &fixed) const;
    Fixed& operator++(void);
    Fixed operator++(int);
    Fixed& operator--(void);
    Fixed operator--(int);
    static Fixed& min(Fixed& a, Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
