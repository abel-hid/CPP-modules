/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 00:08:07 by abel-hid          #+#    #+#             */
/*   Updated: 2024/02/04 20:53:46 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <sstream>

class ScalarConverter
{
private:
    int i;
    float f;
    double d;
    char c;
    ScalarConverter();
    ScalarConverter(ScalarConverter const &sc);
    ScalarConverter &operator=(ScalarConverter const &sc);
    
    public:
        ~ScalarConverter();
        int get_i();
        float get_f();
        double get_d();
        char get_c();
        void set_i(int i);
        void set_f(float f);
        void set_d(double d);
        void set_c(char c);
        static void convert(std::string str);
   
};


#endif